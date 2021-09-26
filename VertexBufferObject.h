#pragma once
#include "Headers.h"

class VertexBufferObject
{
	GLuint id;
public:
	VertexBufferObject(GLfloat* vertices, GLsizeiptr size);
	~VertexBufferObject();
	void bind();
	void unbind();
};