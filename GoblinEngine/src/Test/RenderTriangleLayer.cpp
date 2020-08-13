#include "pch.h"
#include "RenderTriangleLayer.h"

#include "Engine/Window/Window.h"

#include <glad/glad.h>

namespace GoblinEngine
{
	void RenderTriangleLayer::OnAttach()
	{
		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
		};
		
		IVertexBuffer* VBA = GE_RENDER_API_FACTORY.CreateVertexBuffer(vertices, 3 * 3);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		int indecies[3] = { 0, 1, 2 };
		IIndexBuffer* EBO = GE_RENDER_API_FACTORY.CreateIndexBuffer(indecies, 3);
		u_shader.reset(new GoblinEngine::OpenGLShader(
			"C:\\dev\\GoblinEngine\\GoblinEngine\\src\\Test\\Shader\\test.vert", 
			"C:\\dev\\GoblinEngine\\GoblinEngine\\src\\Test\\Shader\\test.frag"));
		u_shader->Use();
	}

	void RenderTriangleLayer::OnUpdate()
	{
		u_shader->Use();
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	}

	void RenderTriangleLayer::OnDetach()
	{
    }
}