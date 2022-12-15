#include "VertexArray.h"
#include "VertexBufferLayout.h"



VertexArray::VertexArray()
	: m_ElementSize(0)
{
	unsigned int vao;
	GLCall(glGenVertexArrays(1, &m_RendererID));

}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind(); // Bind vertex array
	vb.Bind(); // Bind vertex buffer
	const auto& elements = layout.GetElements();
	m_ElementSize = vb.GetSize() / layout.GetStride();

	unsigned int offset = 0; // Pointer offset starts at 0
	/*
	Loop through our vector of VertexBufferElements (Basically a vector of attributes)
	each including all necessary values for a vertexAttribPointer
	*/
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*) offset));
		// Increment offset by the count (number of components) in the attribute by the size of the component
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}

unsigned int VertexArray::GetElementSize() const
{
	return m_ElementSize;
}
