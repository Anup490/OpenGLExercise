#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &id);
}

VertexArrayObject::~VertexArrayObject()
{
	unbind();
	glDeleteVertexArrays(1, &id);
}

void VertexArrayObject::bind()
{
	glBindVertexArray(id);
}

void VertexArrayObject::bind(ElementBufferObject& EBO)
{
	glBindVertexArray(id);
	EBO.bind();
}

void VertexArrayObject::link_VBO_data(VertexBufferObject& VBO, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset)
{
	VBO.bind();
	bind();
	glVertexAttribPointer(index, size, type, normalized, stride, offset);
	glEnableVertexAttribArray(index);
	VBO.unbind();
}

void VertexArrayObject::unbind()
{
	glBindVertexArray(0);
}