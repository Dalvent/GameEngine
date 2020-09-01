#include "pch.h"
#include "Renderer.h"

#include "GoblinEngine/Window/Window.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLShader.h"

namespace GoblinEngine
{
	Renderer::SceneData* Renderer::_sceneData = new SceneData();

	void Renderer::BeginScene(OrthogriphicCamera& camera)
	{
		_sceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(VertexArray& vertexArray, Shader& shader, const glm::mat4& transform)
	{
		shader.Bind();
		switch (GE_RENDER_API.GetUsedApi())
		{
		case SupportedRenderApi::OpenGL:
			static_cast<OpenGLShader&>(shader).SetUniformMat4("u_ViewProjectionMatrix", 
				_sceneData->ViewProjectionMatrix);
			static_cast<OpenGLShader&>(shader).SetUniformMat4("u_Transform", transform);
		default:
			GE_LOG_ASSERT(true, "Renderer::Submit hasn't implemented for chosen render api");
			break;
		}

		vertexArray.Bind();
		GE_RENDER_API.DrawIndexed(vertexArray);
	}
}