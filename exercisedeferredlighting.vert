#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTex;

out vec3 position;
out vec3 normal;
out vec2 texCoord;

void main()
{
	float newx = -aPos.z;
	float newy = aPos.y;
	float newz = -aPos.x;

	vec3 newPos = vec3(newx - 0.5, newy, newz);
	gl_Position = vec4(newPos, 1.0);
	position = aPos;
	normal = aNormal;
	texCoord = aTex;
}