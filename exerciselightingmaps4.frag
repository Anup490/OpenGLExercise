#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;
in vec2 texCoord;

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
	float shininess;
};

struct Light 
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
	vec3 ambient_light = vec3(texture(material.diffuse, texCoord)) * light.ambient;

	vec3 normalized_normal = normalize(normal);
	vec3 light_direction = normalize(light.position - fragPos);
	float diff = max(dot(normalized_normal, light_direction), 0.0f);
	vec3 direct_light = vec3(texture(material.diffuse, texCoord)) * diff * light.diffuse;

	vec3 view_direction = normalize(viewPos - fragPos);
	vec3 reflected = reflect(-light_direction, normalized_normal);
	float spec = pow(max(dot(view_direction, reflected), 0.0f), material.shininess);
	vec3 specular_light = vec3(texture(material.specular, texCoord)) * spec * light.specular;

	vec3 emission_light = vec3(texture(material.emission, texCoord));

	FragColor = texture(material.diffuse, texCoord) * vec4(ambient_light + direct_light + specular_light + emission_light, 1.0f);
}