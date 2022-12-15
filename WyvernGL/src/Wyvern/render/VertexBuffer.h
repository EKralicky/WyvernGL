#pragma once

class VertexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Size;
public:
	// Takes pointer to vertex data array and the size (in bytes) of that data
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const; 
	unsigned int GetSize() const;
};