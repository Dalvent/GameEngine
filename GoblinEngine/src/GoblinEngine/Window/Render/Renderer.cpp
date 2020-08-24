#include "pch.h"
#include "Renderer.h"

#include "GoblinEngine/Window/Window.h"

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
		shader.SetUniformMat4("u_ViewProjectionMatrix", _sceneData->ViewProjectionMatrix);
		shader.SetUniformMat4("u_Transform", transform);

		vertexArray.Bind();
		GE_RENDER_API.DrawIndexed(vertexArray);
	}
}