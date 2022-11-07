#version 330 core
layout (location = 0) out vec4 positionData;
layout (location = 1) out vec4 normalData;
layout (location = 2) out vec4 texData;

in vec3 position;
in vec3 normal;
in vec2 texCoord;

void main()
{
	positionData = vec4(position, 1.0f);
	normalData = vec4(normal, 1.0f);
	texData = vec4(texCoord.x, texCoord.y, 1.0f, 1.0f);
}