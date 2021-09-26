#pragma once
#include "Headers.h"

class ElementBufferObject
{
	GLuint id;
public:
	ElementBufferObject(GLuint* indices, GLsizeiptr size);
	~ElementBufferObject();
	void bind();
	void unbind();
};