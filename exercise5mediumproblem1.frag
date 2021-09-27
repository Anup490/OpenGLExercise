#version 330 core
out vec4 FragColor;
in float scale_value;
void main()
{
	FragColor = vec4(0.23f * scale_value, 0.10f * scale_value, 0.34f * scale_value, 1.0f);
}