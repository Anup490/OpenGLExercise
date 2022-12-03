#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glm/gtx/string_cast.hpp"

const int window_height = 800;
const int window_width = 800;

struct model_data
{
	float* positions;
	float* normals;
	float* tex_coords;
};