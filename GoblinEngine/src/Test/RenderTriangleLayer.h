#pragma once

#include "Engine/Core/Layer.h"
#include "Engine/Window/Platforms/OpenGL/OpenGLShader.h"
#include <memory>

namespace GoblinEngine
{
	class RenderTriangleLayer : public Layer
	{
	public:
		RenderTriangleLayer() : Layer("RenderTriangleLayer")
		{
		}
		void OnAttach() override;
		void OnUpdate() override;
		void OnDetach() override;
	private:
		std::unique_ptr<OpenGLShader> u_shader;
	};
}