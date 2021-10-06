#version 330 core
out vec4 FragColor;
in vec3 normal;
in vec3 fragPos;
uniform vec3 viewPos;

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct Light 
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform Light light;

void main()
{
	vec3 ambient_light = material.ambient * light.ambient;

	vec3 normalized_normal = normalize(normal);
	vec3 light_direction = normalize(light.position - fragPos);
	float diff = max(dot(normalized_normal, light_direction), 0.0f);
	vec3 direct_light = material.diffuse * diff * light.diffuse;

	vec3 view_direction = normalize(viewPos - fragPos);
	vec3 reflected = reflect(-light_direction, normalized_normal);
	float spec = pow(max(dot(view_direction, reflected), 0.0f), 32);
	vec3 specular_light = material.specular * spec * light.specular;

	FragColor = vec4(1.0f, 0.67f, 0.0f, 1.0f) * vec4(ambient_light + direct_light + specular_light, 1.0f);
}