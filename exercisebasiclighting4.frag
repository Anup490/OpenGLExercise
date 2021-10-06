#version 330 core
out vec4 FragColor;
in vec4 lighting;

void main()
{
	FragColor = vec4(1.0f, 0.67f, 0.0f, 1.0f) * lighting;
}