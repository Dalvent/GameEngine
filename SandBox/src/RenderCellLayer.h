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
	GoblinEngine::Ref<GoblinEngine::Shader> s_shader;
	GoblinEngine::Ref<GoblinEngine::VertexArray> s_vertexArray;
	GoblinEngine::Ref<GoblinEngine::OrthogriphicCamera> s_camera;
	GoblinEngine::Ref<GoblinEngine::Texture> s_texture;
	
	GoblinEngine::Transform* _transforms;
	ColorChooseLayer& _colorChoose;
};