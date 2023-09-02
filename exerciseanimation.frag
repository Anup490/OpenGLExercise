#version 330 core
in vec3 position;
in vec3 normal;
in vec2 texcoord;

out vec4 FragColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

void main()
{
	FragColor = texture(texture_diffuse1, texcoord);
}