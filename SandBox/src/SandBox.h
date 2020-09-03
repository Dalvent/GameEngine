#pragma once
#include <IronCat.h>
#include <glm/vec2.hpp>

class SandBox : public IronCat::GameMode
{
public:
	SandBox::SandBox()
		: s_camera(new IronCat::OrthogriphicCamera(-1.0f, 1.0f, -1.0f, 1.0f))
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

	std::shared_ptr<IronCat::OrthogriphicCamera> GetCamera() { return s_camera; }
private:
	std::shared_ptr<IronCat::OrthogriphicCamera> s_camera;
};