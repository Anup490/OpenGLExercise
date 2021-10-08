#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;
in vec2 texCoord;

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct Light 
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;

	vec3 viewer_front;
	float cutoff;
	float outercutoff;
};

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

vec4 default_light()
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
	
	return texture(material.diffuse, texCoord) * vec4(ambient_light + direct_light + specular_light, 1.0f);
}

vec4 directional_light()
{
	vec3 ambient_light = vec3(texture(material.diffuse, texCoord)) * light.ambient;

	vec3 normalized_normal = normalize(normal);
	vec3 light_direction = normalize(vec3(0.2f, 1.0f, 0.3f));
	float diff = max(dot(normalized_normal, light_direction), 0.0f);
	vec3 direct_light = vec3(texture(material.diffuse, texCoord)) * diff * light.diffuse;

	vec3 view_direction = normalize(viewPos - fragPos);
	vec3 reflected = reflect(-light_direction, normalized_normal);
	float spec = pow(max(dot(view_direction, reflected), 0.0f), material.shininess);
	vec3 specular_light = vec3(texture(material.specular, texCoord)) * spec * light.specular;

	return texture(material.diffuse, texCoord) * vec4(ambient_light + direct_light + specular_light, 1.0f);
}

vec4 point_light()
{
	float dist = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + (light.linear * dist) + (light.quadratic * dist * dist));

	vec3 ambient_light = vec3(texture(material.diffuse, texCoord)) * light.ambient * attenuation;

	vec3 normalized_normal = normalize(normal);
	vec3 light_direction = vec3(0.2f, 1.0f, 0.3f);
	float diff = max(dot(normalized_normal, light_direction), 0.0f);
	vec3 direct_light = vec3(texture(material.diffuse, texCoord)) * diff * light.diffuse * attenuation;

	vec3 view_direction = normalize(viewPos - fragPos);
	vec3 reflected = reflect(-light_direction, normalized_normal);
	float spec = pow(max(dot(view_direction, reflected), 0.0f), material.shininess);
	vec3 specular_light = vec3(texture(material.specular, texCoord)) * spec * light.specular * attenuation;

	return texture(material.diffuse, texCoord) * vec4(ambient_light + direct_light + specular_light, 1.0f);
}

vec4 spot_light()
{
	vec3 normalized_normal = normalize(normal);
	vec3 light_direction = normalize(light.position - fragPos);
	float theta = dot(light_direction, normalize(-light.viewer_front));
	vec3 ambient_light = vec3(texture(material.diffuse, texCoord)) * light.ambient;

	float epsilon = light.cutoff - light.outercutoff;
	float intensity = clamp((theta - light.outercutoff)/epsilon, 0.0f, 1.0f);

	float diff = max(dot(normalized_normal, light_direction), 0.0f);
	vec3 direct_light = vec3(texture(material.diffuse, texCoord)) * diff * light.diffuse * intensity;

	vec3 view_direction = normalize(viewPos - fragPos);
	vec3 reflected = reflect(-light_direction, normalized_normal);
	float spec = pow(max(dot(view_direction, reflected), 0.0f), material.shininess);
	vec3 specular_light = vec3(texture(material.specular, texCoord)) * spec * light.specular * intensity;
	
	return texture(material.diffuse, texCoord) * vec4(ambient_light + direct_light + specular_light, 1.0f);
}

void main()
{
	FragColor = spot_light();
}