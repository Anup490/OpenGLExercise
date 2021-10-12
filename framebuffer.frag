#version 330 core
out vec4 FragColor;
in vec2 texCoord;
uniform sampler2D tex;
void main()
{
	vec3 color_incrementer = vec3(0.2f);
	FragColor = texture(tex, texCoord) - vec4(color_incrementer, 0.0f);
}