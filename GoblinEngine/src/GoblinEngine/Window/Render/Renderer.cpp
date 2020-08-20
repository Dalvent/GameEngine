#include "pch.h"
#include "Renderer.h"

#include "GoblinEngine/Window/Window.h"

namespace GoblinEngine
{
	Renderer::SceneData* Renderer::_sceneData = new Renderer::SceneData();

	void Renderer::BeginScene(OrthogriphicCamera& camera)
	{
		_sceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray> vertexArray, const std::shared_ptr<Shader> shader)
	{
		shader->Bind();
		shader->SetUniformMat4("u_ViewProjectionMatrix", _sceneData->ViewProjectionMatrix);

		vertexArray->Bind();
		GE_RENDER_API.DrawIndexed(vertexArray);
	}
}