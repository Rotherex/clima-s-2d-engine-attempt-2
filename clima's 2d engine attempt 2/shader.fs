#version 330 core
out vec4 color;

uniform vec3 renderColor;

void main()
{
	color = vec4(renderColor, 1.0f);
}
