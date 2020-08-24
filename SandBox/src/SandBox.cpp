#include "SandBox.h"
#include <glm/vec2.hpp>

void SandBox::OnBegin()
{
	GE_RENDER_API.SetClearColor(glm::vec4(0.2f, 0.2f, 0.2f, 1));
}

void SandBox::OnEnd()
{
}

void SandBox::OnBeginRenderFrame()
{
	if (GE_INPUT.IsKeyPressed(GE_KEY_W))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(0, 1.0f, 0) * GE_DELTATIME);
	}

	if (GE_INPUT.IsKeyPressed(GE_KEY_A))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(-1.0f, 0, 0) * GE_DELTATIME);
	}

	if (GE_INPUT.IsKeyPressed(GE_KEY_S))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(0, -1.0f, 0) * GE_DELTATIME);
	}

	if (GE_INPUT.IsKeyPressed(GE_KEY_D))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(1.0f, 0, 0) * GE_DELTATIME);
	}
}

void SandBox::OnEndRenderFrame()
{
	GE_RENDER_API.Clear();
}