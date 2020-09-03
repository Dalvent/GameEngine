#include "SandBox.h"
#include <glm/vec2.hpp>

using namespace IronCat;

void SandBox::OnBegin()
{
	RenderApi::SetClearColor(glm::vec4(0.2f, 0.2f, 0.2f, 1));
}

void SandBox::OnEnd()
{
}

void SandBox::OnBeginRenderFrame()
{
	if (IC_INPUT.IsKeyPressed(IC_KEY_W))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(0, 1.0f, 0) * IC_DELTATIME);
	}

	if (IC_INPUT.IsKeyPressed(IC_KEY_A))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(-1.0f, 0, 0) * IC_DELTATIME);
	}

	if (IC_INPUT.IsKeyPressed(IC_KEY_S))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(0, -1.0f, 0) * IC_DELTATIME);
	}

	if (IC_INPUT.IsKeyPressed(IC_KEY_D))
	{
		s_camera->SetPosition(s_camera->GetPosition() + glm::vec3(1.0f, 0, 0) * IC_DELTATIME);
	}

	if (IC_INPUT.IsKeyPressed(IC_KEY_Q))
	{
		s_camera->SetRotaion(s_camera->GetRotation() + 5.0f * IC_DELTATIME);
	}

	if (IC_INPUT.IsKeyPressed(IC_KEY_E))
	{
		s_camera->SetRotaion(s_camera->GetRotation() + -5.0f * IC_DELTATIME);
	}
}

void SandBox::OnEndRenderFrame()
{
	RenderApi::Clear();
}