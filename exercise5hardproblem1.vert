#version 330 core
layout (location = 0) in vec3 aPos;
uniform float scale;
void main()
{
	gl_Position = vec4(aPos * scale, 1.0f);
}