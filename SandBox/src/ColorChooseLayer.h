#pragma once
#include <GoblinEngine.h>
#include <memory>

class ColorChooseLayer : public GoblinEngine::Layer
{
public:
	ColorChooseLayer() :
		GoblinEngine::Layer("ColorChooseLayer")
	{
	}
	void OnImGuiRender() override;

	glm::vec3& GetColor1() { return _color1; }
	glm::vec3& GetColor2() { return _color2; }
	glm::vec3& GetColor3() { return _color3; }
	glm::vec3& GetColor4() { return _color4; }
private:
	glm::vec3 _color1;
	glm::vec3 _color2;
	glm::vec3 _color3;
	glm::vec3 _color4;
};