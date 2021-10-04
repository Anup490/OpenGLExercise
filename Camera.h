#pragma once
#include "Headers.h"
#include "Shader.h"
#include "Window.h"

class Camera
{
	glm::mat4 view, projection;
	glm::vec3 position, target, up, normal;
	Window* pwindow;
	ShaderProgram* pprogram;
	float delta_time = 0.0f, last_frame = 0.0f, current_frame = 0.0f;
	static glm::vec3 front;
	static float yaw, pitch, lastX, lastY, fov;
	static bool first_mouse;
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xpos, double ypos);
public:
	Camera(Window& window, ShaderProgram& program, glm::vec3& position, glm::vec3& target, glm::vec3& up);
	void set_model_matrix(glm::vec3& item_pos, glm::vec3 rotate_axis, float rotate_angle = 0.0f);
	void update_vectors();
	void update_matrices();
};
