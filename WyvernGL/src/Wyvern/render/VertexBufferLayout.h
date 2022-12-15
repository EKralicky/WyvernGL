#pragma once
#include "Renderer.h"


/*
Vertex Buffer Layout Spec:

-> glVertexAttribPointer(index, size, type, normalized, stride, pointer)

index: The index of an attribute in a buffer ignoring the size of the attribute.  
e.g. [1, 1, 1, 2, 2, 3] Indices are numbered by attribute
	Attribute 1 will have index 1
	Attribute 2 will have index 2
	Attribute 3 will have index 3

size(count): The number of components an attribute contains per vertex. NOT the byte size
e.g. 3 floats for a position attribute

type: Data type for each component in the attribute

normalized: Compresses values to be between 0 and 1

stride: The total number of bytes between each VERTEX (the byte size of each vertex in the buffer)

pointer: The offset in bytes to the start of the first element in the attribute
e.g. [1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 3.0f] Indices are numbered by attribute
	Attribute 1 will have pointer 0
	Attribute 2 will have pointer 12 (4 bytes * 3 components)
	Attribute 3 will have pointer 20 (4 bytes * 3 components) + (4 bytes * 2 components)

*/
struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}
		ASSERT(false);
		return 0;
	}
};


class VertexBufferLayout
{

private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;

public:
	VertexBufferLayout()
		: m_Stride(0) {}

	/*
		Responsible for pushing an element onto the vertex buffer layout
	
	*/
	template<typename T>
	void Push(unsigned int count)
	{
		/*
		* TODO this should not throw a compile time error when set to false 
		* but it does anyways ?
		* 
		* I just set it to true for now
		*/
		static_assert(true);  
	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Elements.push_back( { GL_FLOAT, count, GL_FALSE } );
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_Elements.push_back( { GL_UNSIGNED_INT, count, GL_FALSE } );
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back( { GL_UNSIGNED_BYTE, count, GL_TRUE } );
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	
	inline const std::vector<VertexBufferElement> GetElements() const& { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride;  }

};
