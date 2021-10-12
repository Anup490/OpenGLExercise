#version 330 core
out vec4 FragColor;
in vec2 texCoord;
uniform sampler2D tex;

vec4 problem1()
{
	vec3 color_incrementer = vec3(0.2f);
	return texture(tex, texCoord) - vec4(color_incrementer, 0.0f);
}

vec4 problem2()
{
    const float offset = 1.0f / 300.0f;
	vec2 offsets[9] = vec2[](
		vec2(-offset, offset),
		vec2(0.0f, offset),
		vec2(offset, offset),
		vec2(-offset, 0.0f),
		vec2(0.0f, 0.0f),
		vec2(offset, 0.0f),
		vec2(-offset, -offset),
		vec2(0.0f, -offset),
		vec2(offset, -offset)
	);
	float kernel[9] = float[](
        2, 2, 2,
		2, -15, 2,
		2, 2, 2
    );

	vec3 sampleTex[9];
	for(int i=0; i<9; i++)
	{
		sampleTex[i] = vec3(texture(tex, texCoord.st + offsets[i]));
	}

	vec3 color = vec3(0.0f);
	for(int i=0; i<9; i++)
	{
		color += sampleTex[i] * kernel[i];
	}

	return vec4(color, 1.0f);
}

void main()
{
	FragColor = problem2();
}