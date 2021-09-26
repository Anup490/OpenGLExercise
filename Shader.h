#pragma once
#include "Headers.h"
#include <exception>

class ShaderProgram
{
	GLuint id;
	std::string extract_shader(const char* path);
	void compile_shader(GLuint shader_id, const char* shader_source, const char* shader_name);
	template<typename... GLuints> void link_shaders(GLuint shader_id, GLuints... shader_ids);
	void link_shaders();
	template<typename... GLuints> void delete_shaders(GLuint shader_id, GLuints... shader_ids);
	void delete_shaders() {};
public:
	ShaderProgram(const char* vertex_shader_path, const char* fragment_shader_path);
	~ShaderProgram();
	void activate();
	void deactivate();
};