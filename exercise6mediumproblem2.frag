#version 330 core
out vec4 FragCoord;
in vec2 texCoord;
uniform sampler2D tex;
void main()
{
	FragCoord = texture(tex, texCoord);
}