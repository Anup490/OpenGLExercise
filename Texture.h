#pragma once
#include "Headers.h"

class Texture
{
	GLuint id;
public:
	Texture(char const* path, GLint texture_wrap_s, GLint texture_wrap_t, GLint min_filter, GLint mag_filter);
	~Texture();
	void bind();
	void unbind();
};