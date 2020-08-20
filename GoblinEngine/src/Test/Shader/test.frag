#version 410 core

in vec3 v_Position;
in vec4 v_Color;

out vec3 position;
out vec4 color;

void main()
{
	color = v_Color + 0.25;
}