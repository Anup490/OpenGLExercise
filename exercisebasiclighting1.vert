#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in vec3 aNormal;
out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	texCoord = aTex;
	normal = aNormal;

	//Here, normals are transformed with the following formula.
	//Here, our model matrix only rotates and translates but does not scale
	//so therefore, angle between the vectors remains same.
	//And this is why even without using the below formula, the lighting
	//calculations work out.
	//normal = mat3(transpose(inverse(model))) * aNormal;
	fragPos = vec3(model * vec4(aPos, 1.0f));
}