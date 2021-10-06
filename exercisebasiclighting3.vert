#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
out vec3 normal;
out vec3 fragPos_view;
out vec3 lightPos_view;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightPos;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	normal = mat3(transpose(inverse(view))) * mat3(transpose(inverse(model))) * aNormal;
	lightPos_view = vec3(view * vec4(lightPos, 1.0f));
	fragPos_view = vec3(view * model * vec4(aPos, 1.0f));
}