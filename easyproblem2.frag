#version 330 core
out vec4 FragColor;

float invert_color(float color)
{
	return 1.0f - color;
}

void main()
{
	FragColor = vec4(invert_color(0.23f), invert_color(0.10f), invert_color(0.34f), 1.0f);
}