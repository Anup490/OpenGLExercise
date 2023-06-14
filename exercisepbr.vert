#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in vec3 aNormal;
out vec2 texCoord;
out vec3 worldPos;
out vec3 normal;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	worldPos = (model * vec4(aPos, 1.0f)).xyz;
	texCoord = aTex;
	normal = mat3(transpose(inverse(model))) * aNormal;
}