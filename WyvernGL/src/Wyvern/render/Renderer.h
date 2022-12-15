#pragma once
#include "Wyvern.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"


#define ASSERT(x) if (!(x)) __debugbreak(); // msvc debugger break function
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{

private:


public:
    void Clear() const;
    void ClearDepthBuffer() const;
    void DrawIndices(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, GLenum draw_type) const;
    void DrawArrays(const VertexArray& va, const Shader& shader, GLenum draw_type) const;

};