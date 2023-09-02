#version 330 core
layout (location = 0) in vec3 v_position;
layout (location = 1) in vec3 v_normal;
layout (location = 2) in vec2 v_texcoord;
//layout (location = 3) in vec3 v_tangent;
//layout (location = 4) in vec3 v_bitangent;
//layout (location = 5) in ivec4 v_boneIDs;
//layout (location = 6) in vec4 v_weights;
layout (location = 3) in mat4 node_model;

out vec3 position;
out vec3 normal;
out vec2 texcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	normal = mat3(transpose(inverse(model))) * v_normal;
	texcoord = v_texcoord;
	gl_Position = projection * view * model * node_model * vec4(v_position, 1.0f);
}