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

struct DirLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight
{
	float constant;
	float linear;
	float quadratic;

	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 color;
};

struct SpotLight
{
	vec3 front;
	float cutoff;
	float outercutoff;

	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform vec3 viewPos;
uniform Material material;
uniform DirLight dirLight;
uniform SpotLight spotLight;

#define NR_POINT_LIGHTS 4
uniform PointLight pointLights[NR_POINT_LIGHTS];

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewPos);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewPos);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewPos);

void main()
{
	vec3 normalized_normal = normalize(normal);
	vec3 normalized_viewpos = normalize(viewPos);
	vec3 fragcolor = CalcDirLight(dirLight, normalized_normal, normalized_viewpos);
	for(int i = 0; i < NR_POINT_LIGHTS; i++)
	{
		fragcolor += CalcPointLight(pointLights[i], normalized_normal, normalized_viewpos);
	}
	fragcolor += CalcSpotLight(spotLight,  normalized_normal, normalized_viewpos);
	FragColor = vec4(fragcolor, 1.0f);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewPos)
{
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoord));

	float diff = max(dot(normal, viewPos),0.0f);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoord));

	vec3 lightdir = normalize(light.position - fragPos);
	vec3 reflectlight = reflect(normalize(-lightdir), normal);
	float spec = max(dot(reflectlight, viewPos), 0.0f);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoord));

	return ambient + diffuse + specular;
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewPos)
{
	float dist = length(fragPos - light.position);
	float attenuation = 1.0f/(light.constant + (light.linear * dist) + (light.quadratic * dist * dist));

	vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoord)) * attenuation * light.color;

	vec3 normalized_lightdir = normalize(light.position - fragPos);

	float diff = max(dot(normal, normalized_lightdir),0.0f);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoord)) * attenuation * light.color;;

	vec3 normalized_viewdir = normalize(viewPos - fragPos);
	vec3 reflectlight = normalize(reflect(-normalized_lightdir, normal));
	float spec = pow(max(dot(reflectlight, normalized_viewdir), 0.0f), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoord)) * attenuation * light.color;;

	return ambient + diffuse + specular;
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewPos)
{	
	vec3 normalized_lightdir = normalize(light.position - fragPos);

	float theta = dot(normalize(light.front), normalized_lightdir);
	float epsilon = light.cutoff - light.outercutoff;
	float intensity = clamp((theta - light.outercutoff)/ epsilon, 0.0f, 1.0f);

	vec3 normalized_reflected = reflect(-normalized_lightdir, normal);

	vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoord)) * intensity;

	float diff = max(dot(normal, normalized_lightdir), 0.0f);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoord)) * intensity;

	vec3 normalized_viewdir = normalize(viewPos - fragPos);
	float spec = pow(max(dot(normalized_reflected, normalized_viewdir), 0.0f), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoord)) * intensity;

	return ambient + diffuse + specular;
}