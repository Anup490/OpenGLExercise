#version 330 core
out vec4 FragColor;
in vec2 fbTexCoord;
uniform sampler2D positionTexture;
uniform sampler2D normalTexture;
uniform sampler2D texCoordTexture;
void main()
{
	vec3 light_pos = vec3(0.0f,0.0f,0.0f);
	vec3 position = vec3(texture(positionTexture, fbTexCoord));
	vec3 normal = vec3(texture(normalTexture, fbTexCoord));
	vec3 texCoord = vec3(texture(texCoordTexture, fbTexCoord));
	
	vec3 view = light_pos - position;
	float dot_val = dot(normal, view);
	vec4 color = texture(texCoordTexture, fbTexCoord);		
	if (dot_val < 0.0f)
		dot_val = -dot_val;
	if (texCoord.z > 0.0f)
		FragColor = vec4(color.x * dot_val, color.y * dot_val, color.y * dot_val, 1.0f);
	else 
		FragColor = color;
}