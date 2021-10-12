#include "ReverseCamera.h"

ReverseCamera::ReverseCamera(Window& window, glm::vec3& position, glm::vec3& target, glm::vec3& up)
{
	ReverseCamera::pwindow = &window;
	ReverseCamera::position = position;
	ReverseCamera::target = target;
	ReverseCamera::up = up;
	ReverseCamera::view = glm::mat4(1.0f);
	ReverseCamera::projection = glm::mat4(1.0f);

	glm::vec3 direction = glm::normalize(position - target);
	ReverseCamera::normal = glm::normalize(up);
	glm::vec3 right = glm::normalize(glm::cross(normal, direction));

	glm::vec3 orientation;
	orientation.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	orientation.y = sin(glm::radians(pitch));
	orientation.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(orientation);
}

void ReverseCamera::set_model_matrix(ShaderProgram& program, glm::vec3& item_pos, glm::vec3 rotate_axis, float rotate_angle, glm::vec3 scalar)
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, scalar);
	model = glm::translate(model, item_pos);
	model = glm::rotate(model, glm::radians(rotate_angle), rotate_axis);
	program.set_mat4_uniform("model", model);
}

void ReverseCamera::set_view_matrix(ShaderProgram& program)
{
	ReverseCamera::view = glm::lookAt(position, position + front, normal);
	program.set_mat4_uniform("view", ReverseCamera::view);
}

void ReverseCamera::set_projection_matrix(ShaderProgram& program, float fov)
{
	ReverseCamera::fov = fov;
	ReverseCamera::projection = glm::perspective(fov, float(window_width / window_height), 0.1f, 100.0f);
	program.set_mat4_uniform("projection", ReverseCamera::projection);
}

void ReverseCamera::update_vectors()
{
	current_frame = pwindow->get_current_time();
	delta_time = current_frame - last_frame;
	last_frame = current_frame;

	const float camera_speed = 2.5f * delta_time;
	if (pwindow->has_pressed(GLFW_KEY_W))
		position -= camera_speed * front;
	if (pwindow->has_pressed(GLFW_KEY_S))
		position += camera_speed * front;
	if (pwindow->has_pressed(GLFW_KEY_A))
		position += glm::normalize(glm::cross(front, up)) * camera_speed;
	if (pwindow->has_pressed(GLFW_KEY_D))
		position -= glm::normalize(glm::cross(front, up)) * camera_speed;
}

void ReverseCamera::update_matrices(ShaderProgram& program)
{
	ReverseCamera::view = glm::lookAt(position, position + front, normal);
	program.set_mat4_uniform("view", view);
	ReverseCamera::projection = glm::perspective(glm::radians(fov), float(window_width / window_height), 0.1f, 100.0f);
	program.set_mat4_uniform("projection", projection);
}

glm::vec3 ReverseCamera::get_position()
{
	return position;
}

glm::vec3 ReverseCamera::get_front()
{
	return front;
}

void ReverseCamera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (first_mouse)
	{
		lastX = xpos;
		lastY = ypos;
		first_mouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = ypos - lastY;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(direction);
}

void ReverseCamera::scroll_callback(GLFWwindow* window, double xpos, double ypos)
{
	/*fov -= (float)ypos;
	if (fov < 1.0f)
		fov = 1.0f;
	if (fov > 45.0f)
		fov = 45.0f;*/
}