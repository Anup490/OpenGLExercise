#version 330 core
out vec4 FragColor;
in vec3 normal;
in vec3 fragPos;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
void main()
{
	float ambient_strength = 0.1f;
	vec3 ambient_light = ambient_strength * lightColor;

	vec3 normalized_normal = normalize(normal);
	vec3 light_direction = normalize(lightPos - fragPos);
	float diff = max(dot(normalized_normal, light_direction), 0.0f);
	vec3 direct_light = diff * lightColor;

	float specular_strength = 0.5f;
	vec3 view_direction = normalize(viewPos - fragPos);
	vec3 reflected = reflect(-light_direction, normalized_normal);
	float spec = pow(max(dot(view_direction, reflected), 0.0f), 32);
	vec3 specular_light = specular_strength * spec * lightColor;

	FragColor = vec4(1.0f, 0.67f, 0.0f, 1.0f) * vec4(ambient_light + direct_light + specular_light, 1.0f);
}