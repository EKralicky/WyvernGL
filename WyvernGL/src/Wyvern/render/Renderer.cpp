#include "Renderer.h"

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}


bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << function <<
            " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::ClearDepthBuffer() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT););
}

void Renderer::DrawIndices(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, GLenum draw_type) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();

    GLCall(glDrawElements(draw_type, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::DrawArrays(const VertexArray& va, const Shader& shader, GLenum draw_type) const
{
    shader.Bind();
    va.Bind();

    GLCall(glDrawArrays(draw_type, 0, va.GetElementSize()));
}
