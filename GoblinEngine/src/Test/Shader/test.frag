#version 410 core

in vec3 v_Position;

out vec4 color;

void main()
{
	color = vec4(v_Position + 0.75, 1.0);
}