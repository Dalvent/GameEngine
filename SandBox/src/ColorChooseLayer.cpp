#include "ColorChooseLayer.h"
#include <imgui.h>
#include <glm\gtc\type_ptr.hpp>

void ColorChooseLayer::OnImGuiRender()
{
	ImGui::Begin("Sq color");
	ImGui::ColorEdit3("COLOR1", glm::value_ptr(_color1));
	ImGui::ColorEdit3("COLOR2", glm::value_ptr(_color2));
	ImGui::ColorEdit3("COLOR3", glm::value_ptr(_color3));
	ImGui::ColorEdit3("COLOR4", glm::value_ptr(_color4));
	ImGui::End();
}
