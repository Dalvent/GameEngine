#include "pch.h"
#include "Renderer.h"

#include "IronCat/Render/RenderApi.h"
#include "IronCat/Platforms/OpenGL/OpenGLShader.h"

namespace IronCat
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
		switch (RenderApi::GetUsedApi())
		{
		case SupportedRenderApiType::OpenGL:
			static_cast<OpenGLShader&>(shader).SetUniformMat4("u_ViewProjectionMatrix", 
				_sceneData->ViewProjectionMatrix);
			static_cast<OpenGLShader&>(shader).SetUniformMat4("u_Transform", transform);
		default:
			IC_LOG_CORE_ASSERT(true, "Renderer::Submit hasn't implemented for chosen render api");
			break;
		}

		vertexArray.Bind();
		RenderApi::DrawIndexed(vertexArray);
	}
}