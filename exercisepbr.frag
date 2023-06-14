#version 330 core
out vec4 FragColor;
in vec2 texCoord;
in vec3 worldPos;
in vec3 normal;
uniform sampler2D tex0;
uniform sampler2D tex1;

#define PI 3.14159265359f

float normal_distribution(float roughness, vec3 normal, vec3 halfway_vec);
float geometry_smith(vec3 normal, vec3 frag2Light, vec3 frag2Cam, float roughness);
vec3 fresnel_shlick(vec3 F0_base_reflectivity, float dotNWi);

void main()
{
	vec3 light_position = vec3(0.0f, 0.0f, 3.0f);
	vec3 cam_position = vec3(0.0f, 0.0f, 3.0f);
	float light_intensity = 10.0f;
	float samples = 1.0f;
	float dw = 1.0f/samples;
	vec3 c_surface_color = vec3(1.0f, 1.0f, 1.0f);
	float roughness = 1.0f;
	float metalness = 1.0f;
	vec3 F0_base_reflectivity = vec3(0.04f);

	F0_base_reflectivity = mix(F0_base_reflectivity, c_surface_color, metalness);

	float dist_to_light = length(light_position);
	float attenuation = 1.0f/(dist_to_light * dist_to_light);
	vec3 L_radiance = c_surface_color * light_intensity * attenuation ;

	vec3 wi_light_dir = normalize(light_position - worldPos);
	vec3 wo_cam_dir = normalize(cam_position - worldPos);
	vec3 halfway_vec = normalize(wi_light_dir+wo_cam_dir);
	float dotNWi = max(dot(normal, wi_light_dir), 0.0f);
	float dotNWo = max(dot(normal, wo_cam_dir), 0.0f);

	float NDF = normal_distribution(roughness, normal, halfway_vec);
	float G_geometry_func = geometry_smith(normal, wi_light_dir, wo_cam_dir, roughness);
	vec3 F_Fresnel = fresnel_shlick(F0_base_reflectivity, dotNWi);
	vec3 kd_diffuse_light_fraction = 1.0f - F_Fresnel;

	vec3 numerator = NDF * G_geometry_func * F_Fresnel;
	float denominator = 4.0f * dotNWi * dotNWo;

	vec3 T1 = (kd_diffuse_light_fraction * c_surface_color)/PI;
	vec3 T2 = numerator/denominator;
	vec3 T3 = L_radiance * dotNWi * dw;

	vec3 finalColor = (T1 + T2) * T3;
	vec3 texColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.5).xyz;
	FragColor = vec4(finalColor, 1.0);
}

float normal_distribution(float roughness, vec3 normal, vec3 halfway_vec)
{
	float dotNhalfway_vec = max(dot(normal, halfway_vec), 0.0f);
	float dotNhalfway_vec_squared = dotNhalfway_vec * dotNhalfway_vec;
	float roughness_squared = roughness * roughness;
	float A = (dotNhalfway_vec_squared * (roughness_squared - 1.0f)) + 1.0f;
	return roughness_squared/(A * A * PI);
}

float geometry_ggx(vec3 n, vec3 v, float k)
{
	float dotNV = max(dot(n,v), 0.0f);
	float denom = (dotNV * (1.0f - k)) + k;
	return dotNV/denom;
}

float geometry_smith(vec3 normal, vec3 frag2Light, vec3 frag2Cam, float roughness)
{
	float k = pow(roughness + 1.0f, 2)/8.0f;
	return geometry_ggx(normal, frag2Light, k) * geometry_ggx(normal, frag2Cam, k);
}

vec3 fresnel_shlick(vec3 F0_base_reflectivity, float dotNWi)
{
	return F0_base_reflectivity + (1.0f - F0_base_reflectivity) * pow(1.0f - dotNWi, 5);
}