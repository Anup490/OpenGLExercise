#version 330 core
out vec4 FragColor;
uniform vec3 light_color;
uniform float light_intensity;
void main()
{
	FragColor = vec4(light_color * light_intensity, 1.0f);
}