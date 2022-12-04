#version 330 core
out vec4 FragColor;
in vec2 fbTexCoord;
uniform sampler2D positionTexture;
uniform sampler2D normalTexture;
uniform sampler2D texCoordTexture;
uniform sampler2D depthTexture;
void main()
{
	vec3 light_pos = vec3(0.0f,0.0f,0.0f);
	vec3 position = vec3(texture(positionTexture, fbTexCoord));
	vec3 normal = vec3(texture(normalTexture, fbTexCoord));
	vec3 texCoord = vec3(texture(texCoordTexture, fbTexCoord));
	
	vec3 view = light_pos - position;
	float dot_val = dot(normal, view);

	float depth = texture(depthTexture, fbTexCoord).r;
	float occlusion_factor = 1.0f;
	const int samples = 81;//increase value for better results
	float d_occlusion_factor = 1.0f / samples;
	float sample_depth;
	vec2 sample_texcoords;
	for (float dx = -d_occlusion_factor; dx <= d_occlusion_factor; dx+= d_occlusion_factor)
	{
		for (float dy = -d_occlusion_factor; dy <= d_occlusion_factor; dy+= d_occlusion_factor)
		{
			sample_texcoords = vec2(fbTexCoord.x + dx, fbTexCoord.y + dy);
			if (sample_texcoords.x > 0.0f && sample_texcoords.x < 1.0f && sample_texcoords.y > 0.0f && sample_texcoords.y < 1.0f)
			{
				sample_depth = texture(depthTexture, sample_texcoords).r;
				if (sample_depth > depth)
					occlusion_factor -= d_occlusion_factor;
			}
		}
	}	

	if (occlusion_factor < 1.0f)
	{
		depth *= occlusion_factor;
		FragColor = vec4(vec3(depth, depth, depth), 1.0f);
	}
	else
		FragColor = vec4(vec3(depth, depth, depth), 1.0f);
}