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

	const int window_width = 800;
	const int window_height = 800;
	const int samples_x = 5;
	const int samples_y = 5;

	const int samples = samples_x * samples_y;
	float diff_occlusion_factor = 1.0f / samples;
	float x_diff = 1.0f / window_width;
	float y_diff = 1.0f / window_height;
	float sample_depth;
	float half_sample_x = (samples_x - 1)/2.0f;
	float half_sample_y = (samples_y - 1)/2.0f;
	vec2 sample_texcoords = fbTexCoord;
	sample_texcoords.x -= (half_sample_x * x_diff);
	sample_texcoords.y -= (half_sample_y * y_diff);
	for (int y = 0; y < samples_y; y++)
	{
		for (int x = 0; x < samples_x; x++)
		{
			if (sample_texcoords.x > 0.0f && sample_texcoords.x < 1.0f && sample_texcoords.y > 0.0f && sample_texcoords.y < 1.0f)
			{
				sample_depth = texture(depthTexture, sample_texcoords).r;
				if (sample_depth < depth)
					occlusion_factor -= diff_occlusion_factor;
				sample_texcoords.x += x_diff;
			}
		}
		sample_texcoords.y += y_diff;
		sample_texcoords.x -= (samples_x * x_diff);
	}

	depth *= occlusion_factor;
	FragColor = vec4(vec3(depth, depth, depth), 1.0f);
}