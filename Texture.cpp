#include "Texture.h"
#include "stb/stb_image.h"

Texture::Texture(char const* path, GLint texture_wrap_s, GLint texture_wrap_t, GLint min_filter, GLint mag_filter)
{
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture_wrap_s);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture_wrap_t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

	stbi_set_flip_vertically_on_load(true);
	int width, height, color_channels;
	unsigned char* data = stbi_load(path, &width, &height, &color_channels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);
	}
}

Texture::~Texture()
{
	unbind();
	glDeleteTextures(1, &id);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}