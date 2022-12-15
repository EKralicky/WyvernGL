#pragma once

class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned long m_Count;
public:
	IndexBuffer(const unsigned long* data, unsigned long count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return m_Count; }
};