#pragma once

#include "IronCat/Render/OrthogriphicCamera.h"
#include "IronCat/Render/RenderApi.h"

namespace IronCat
{
	class Renderer
	{
	public:
		static void BeginScene(OrthogriphicCamera& camera);
		static void EndScene();

		static void Submit(VertexArray& vertexArray, Shader& shader, const glm::mat4& transform);
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* _sceneData;
	};
}