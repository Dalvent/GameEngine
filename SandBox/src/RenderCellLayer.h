#pragma once
#include <IronCat.h>
#include <memory>
#include "ColorChooseLayer.h"

class RenderCellLayer : public IronCat::Layer
{
public:
	RenderCellLayer(IronCat::Ref<IronCat::OrthogriphicCamera> camera,
		ColorChooseLayer& colorChoose) : IronCat::Layer("RenderTriangleLayer"),
		s_camera(camera), _colorChoose(colorChoose)
	{
	}
	void OnAttach() override;
	void OnUpdate() override;
	void OnDetach() override;
private:
	IronCat::Transform* CreateTransforms();
private:
	IronCat::Ref<IronCat::Shader> s_shader;
	IronCat::Ref<IronCat::VertexArray> s_vertexArray;
	IronCat::Ref<IronCat::OrthogriphicCamera> s_camera;
	IronCat::Ref<IronCat::Texture> s_texture;
	
	IronCat::Transform* _transforms;
	ColorChooseLayer& _colorChoose;
};