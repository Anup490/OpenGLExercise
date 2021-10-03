#include "Wrappers.h"

namespace ExerciseCamera
{
	static float yaw = -90.0f;
	static float pitch = 0.0f;
	static float lastX = 400.0f;
	static float lastY = 400.0f;
	static float fov = 45.0f;
	static bool first_mouse = false;
	static glm::vec3 camera_front;

	static void update_camera_vectors(Window& window, glm::vec3& camera_pos, glm::vec3& camera_front, glm::vec3& camera_up, float& current_frame);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xpos, double ypos);

	int problem1()
	{
		GLfloat square_vertices[] =
		{
			//VERTICES            TEXCOORDS
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

		glm::vec3 cubePositions[] = {
			glm::vec3(0.0f,  0.0f,  0.0f),
			glm::vec3(2.0f,  5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f,  3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f,  2.0f, -2.5f),
			glm::vec3(1.5f,  0.2f, -1.5f),
			glm::vec3(-1.3f,  1.0f, -1.5f)
		};

		const char* window_title = "OpenGLExerciseCamera 1";
		Window window(window_title);
		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exercisecamera.vert", "exercisecamera.frag");
		shader.set_int_uniform("tex0", 0);
		shader.set_int_uniform("tex1", 1);

		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		Texture tex1("happy.png", GL_TEXTURE0, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGBA);
		Texture tex2("container.png", GL_TEXTURE1, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGB);

		glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 camera_direction = glm::normalize(camera_pos - camera_target);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 camera_right = glm::normalize(glm::cross(up, camera_direction));
		glm::vec3 camera_up = glm::cross(camera_direction, camera_right);

		glm::vec3 direction;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		camera_front = glm::normalize(direction);

		float aspect_ratio = 1.0f;
		float current_frame = 0.0f, last_frame = 0.0f, delta_time = 0.0f;

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(fov), aspect_ratio, 0.1f, 100.0f);

		shader.set_mat4_uniform("projection", projection);

		glEnable(GL_DEPTH_TEST);

		window.activate_mouse_input(mouse_callback, scroll_callback);

		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			VAO.bind();
			shader.activate();

			current_frame = window.get_current_time();
			delta_time = current_frame - last_frame;
			last_frame = current_frame;

			update_camera_vectors(window, camera_pos, camera_front, camera_up, delta_time);
			glm::mat4 view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
			shader.set_mat4_uniform("view", view);

			for (unsigned int i = 0; i < 10; i++)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, cubePositions[i]);
				model = glm::rotate(model, glm::radians(20.0f * i), glm::vec3(0.5f, 1.0f, 1.0f));
				shader.set_mat4_uniform("model", model);
				projection = glm::perspective(glm::radians(fov), aspect_ratio, 0.1f, 100.0f);
				shader.set_mat4_uniform("projection", projection);
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}

	void update_camera_vectors(Window& window, glm::vec3& camera_pos, glm::vec3& camera_front, glm::vec3& camera_up, float& current_frame)
	{
		const float camera_speed = 2.5f * current_frame;
		if (window.has_pressed(GLFW_KEY_W))
			camera_pos += camera_speed * camera_front;
		if (window.has_pressed(GLFW_KEY_S))
			camera_pos -= camera_speed * camera_front;
		if (window.has_pressed(GLFW_KEY_A))
			camera_pos -= glm::normalize(glm::cross(camera_front, camera_up)) * camera_speed;
		if (window.has_pressed(GLFW_KEY_D))
			camera_pos += glm::normalize(glm::cross(camera_front, camera_up)) * camera_speed;
	}

	void mouse_callback(GLFWwindow* window, double xpos, double ypos)
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
		camera_front = glm::normalize(direction);
	}

	void scroll_callback(GLFWwindow* window, double xpos, double ypos)
	{
		fov -= (float)ypos;
		if (fov < 1.0f)
			fov = 1.0f;
		if (fov > 45.0f)
			fov = 45.0f;
	}
}