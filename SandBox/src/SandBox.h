#pragma once
#include <GoblinEngine.h>
#include <glm/vec2.hpp>

class SandBox : public GoblinEngine::GameMode
{
public:
	SandBox::SandBox()
		: s_camera(new GoblinEngine::OrthogriphicCamera(-1.0f, 1.0f, -1.0f, 1.0f))
	{
		s_camera->SetPosition(glm::vec3(0, 0, 0));
	}
	SandBox::~SandBox()
	{
	}

	void OnBegin() override;
	void OnEnd() override;
	void OnBeginRenderFrame() override;
	void OnEndRenderFrame() override;

	std::shared_ptr<GoblinEngine::OrthogriphicCamera> GetCamera() { return s_camera; }
private:
	std::shared_ptr<GoblinEngine::OrthogriphicCamera> s_camera;
};