#pragma once
#include "Headers.h"
#include "Shader.h"
#include "BaseCamera.h"

class ReverseCamera : public BaseCamera
{
	glm::mat4 view, projection;
	glm::vec3 position, target, up, normal;
	Window* pwindow;
	float delta_time = 0.0f, last_frame = 0.0f, current_frame = 0.0f, yaw = 90.0f, pitch = 0.0f, lastX = 0.0f, lastY = 0.0f, fov = 45.0f;
	glm::vec3 front = glm::vec3(0.0f, 0.0f, 0.0f);
	bool first_mouse = false;
public:
	ReverseCamera(Window& window, glm::vec3& position, glm::vec3& target, glm::vec3& up);
	void set_model_matrix(ShaderProgram& program, glm::vec3& item_pos, glm::vec3 rotate_axis, float rotate_angle = 0.0f, glm::vec3 scalar = glm::vec3(1.0f));
	void set_view_matrix(ShaderProgram& program);
	void set_projection_matrix(ShaderProgram& program, float fov = 45.0f);
	void update_vectors();
	void update_matrices(ShaderProgram& program);
	glm::vec3 get_position();
	glm::vec3 get_front();
	void mouse_callback(GLFWwindow* window, double xpos, double ypos) override;
	void scroll_callback(GLFWwindow* window, double xpos, double ypos) override;
};
#pragma once
