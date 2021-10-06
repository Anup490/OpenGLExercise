#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec4 lighting;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	vec3 normal = mat3(transpose(inverse(model))) * aNormal;
	vec3 fragPos = vec3(model * vec4(aPos, 1.0f));

	float ambient_strength = 0.1f;
	vec3 ambient_light = ambient_strength * lightColor;

	vec3 normalized_normal = normalize(normal);
	vec3 light_direction = normalize(lightPos - fragPos);
	float diff = max(dot(normalized_normal, light_direction), 0.0f);
	vec3 direct_light = diff * lightColor;

	float specular_strength = 1.0f;
	vec3 view_direction = normalize(viewPos - fragPos);
	vec3 reflected = reflect(-light_direction, normalized_normal);
	float spec = pow(max(dot(view_direction, reflected), 0.0f), 32);
	vec3 specular_light = specular_strength * spec * lightColor;

	lighting = vec4(ambient_light + direct_light + specular_light, 1.0f);
}