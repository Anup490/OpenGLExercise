#pragma once
#include "Headers.h"

class Texture
{
	GLuint id;
	GLenum texture_container;
public:
	Texture
	(
		char const* path, 
		GLenum texture_container, 
		GLint texture_wrap_s, 
		GLint texture_wrap_t, 
		GLint min_filter, 
		GLint mag_filter,
		GLenum img_color_channels
	);
	~Texture();
	void activate();
	void deactivate();
};