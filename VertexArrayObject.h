#pragma once
#include "Headers.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"

class VertexArrayObject
{
	GLuint id;
public:
	VertexArrayObject();
	~VertexArrayObject();
	void bind();
	void bind(ElementBufferObject& EBO);
	void link_VBO_data(VertexBufferObject& VBO, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	void unbind();
};