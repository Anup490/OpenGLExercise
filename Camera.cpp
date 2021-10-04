#include "Camera.h"

float Camera::yaw = -90.f;
float Camera::pitch = 0.0f;
bool Camera::first_mouse = false;
float Camera::lastX = 0.0f;
float Camera::lastY = 0.0f;
float Camera::fov = 45.0f;
glm::vec3 Camera::front = glm::vec3(0.0f, 0.0f, 0.0f);

Camera::Camera(Window& window, ShaderProgram& program, glm::vec3& position, glm::vec3& target, glm::vec3& up)
{
	Camera::pwindow = &window;
	Camera::pprogram = &program;
	Camera::position = position;
	Camera::target = target;
	Camera::up = up;

	glm::vec3 direction = glm::normalize(position - target);
	Camera::normal = glm::normalize(up);
	glm::vec3 right = glm::normalize(glm::cross(normal, direction));
	
	glm::vec3 orientation;
	orientation.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	orientation.y = sin(glm::radians(pitch));
	orientation.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(orientation);

	Camera::view = glm::lookAt(position, position + front, normal);
	Camera::projection = glm::perspective(fov, float(window_width / window_height), 0.1f, 100.0f);
	pprogram->set_mat4_uniform("view", Camera::view);
	pprogram->set_mat4_uniform("projection", Camera::projection);

	pwindow->activate_mouse_input(mouse_callback, scroll_callback);
}

void Camera::set_model_matrix(glm::vec3& item_pos, glm::vec3 rotate_axis, float rotate_angle)
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, item_pos);
	model = glm::rotate(model, glm::radians(rotate_angle), rotate_axis);
	pprogram->set_mat4_uniform("model", model);
}

void Camera::update_vectors()
{
	current_frame = pwindow->get_current_time();
	delta_time = current_frame - last_frame;
	last_frame = current_frame;

	const float camera_speed = 2.5f * delta_time;
	if (pwindow->has_pressed(GLFW_KEY_W))
		position += camera_speed * front;
	if (pwindow->has_pressed(GLFW_KEY_S))
		position -= camera_speed * front;
	if (pwindow->has_pressed(GLFW_KEY_A))
		position -= glm::normalize(glm::cross(front, up)) * camera_speed;
	if (pwindow->has_pressed(GLFW_KEY_D))
		position += glm::normalize(glm::cross(front, up)) * camera_speed;
}

void Camera::update_matrices()
{
	Camera::view = glm::lookAt(position, position + front, normal);
	pprogram->set_mat4_uniform("view", view);
	Camera::projection = glm::perspective(glm::radians(fov), float(window_width / window_height), 0.1f, 100.0f);
	pprogram->set_mat4_uniform("projection", projection);
}

void Camera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (first_mouse)
	{
		lastX = xpos;
		lastY = ypos;
		first_mouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
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

void Camera::scroll_callback(GLFWwindow* window, double xpos, double ypos)
{
	fov -= (float)ypos;
	if (fov < 1.0f)
		fov = 1.0f;
	if (fov > 45.0f)
		fov = 45.0f;
}