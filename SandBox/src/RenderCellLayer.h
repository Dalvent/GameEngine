#pragma once
#include <GoblinEngine.h>
#include <memory>
#include "ColorChooseLayer.h"

class RenderCellLayer : public GoblinEngine::Layer
{
public:
	RenderCellLayer(GoblinEngine::Ref<GoblinEngine::OrthogriphicCamera> camera,
		ColorChooseLayer& colorChoose) : GoblinEngine::Layer("RenderTriangleLayer"),
		s_camera(camera), _colorChoose(colorChoose)
	{
	}
	void OnAttach() override;
	void OnUpdate() override;
	void OnDetach() override;
private:
	GoblinEngine::Transform* CreateTransforms();
private:
	std::shared_ptr<GoblinEngine::Shader> s_shader;
	std::shared_ptr<GoblinEngine::VertexArray> s_vertexArray;
	std::shared_ptr<GoblinEngine::OrthogriphicCamera> s_camera;
	
	GoblinEngine::Transform* _transforms;
	ColorChooseLayer& _colorChoose;
};