#include "Wrappers.h"

namespace ExerciseMaterials
{
	int problem1()
	{
		GLfloat square_vertices[] = {
			-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

			-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

			-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

			-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
		};

		GLfloat light_vertices[] =
		{
			//VERTICES            
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
		};

		glm::vec3 cubePosition(0.0f);
		glm::vec3 light_position(2.0f, 2.0f, 1.0f);

		const char* window_title = "OpenGLExerciseMaterials";
		Window window(window_title);

		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exercisematerials1.vert", "exercisematerials1.frag");

		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		VertexBufferObject light_VBO(light_vertices, sizeof(light_vertices));
		ShaderProgram light_shader("materiallight.vert", "materiallight.frag");
		VertexArrayObject light_VAO;
		light_VAO.link_VBO_data(light_VBO, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

		glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 camera_target = glm::vec3(0.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		Camera camera(window, camera_pos, camera_target, up);
		camera.set_view_matrix(shader);
		camera.set_projection_matrix(shader);
		camera.set_view_matrix(light_shader);
		camera.set_projection_matrix(light_shader);

		shader.set_vec3_uniform("material.ambient", glm::vec3(1.0f, 0.5f, 0.31f));
		shader.set_vec3_uniform("material.diffuse", glm::vec3(1.0f, 0.5f, 0.31f));
		shader.set_vec3_uniform("material.specular", glm::vec3(0.5f));
		shader.set_float_uniform("material.shininess", 32.0f);

		glm::vec3 light_color;
		light_color.x = sin(glfwGetTime() * 2.0f);
		light_color.y = sin(glfwGetTime() * 0.7f);
		light_color.z = sin(glfwGetTime() * 1.3f);

		glm::vec3 diffuse_color = light_color * glm::vec3(0.5f);
		glm::vec3 ambient_color = diffuse_color * glm::vec3(0.2f);

		shader.set_vec3_uniform("light.ambient", ambient_color);
		shader.set_vec3_uniform("light.diffuse", diffuse_color);
		shader.set_vec3_uniform("light.position", light_position);
		shader.set_vec3_uniform("light.specular", glm::vec3(1.0f));

		light_shader.set_vec3_uniform("light_color", light_color);

		glEnable(GL_DEPTH_TEST);

		float prev_time = window.get_current_time();
		float crnt_time;

		while (window.should_stay())
		{
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			VAO.bind();
			shader.activate();

			crnt_time = window.get_current_time();
			if ((crnt_time - prev_time) > 1.0f)
			{
				light_color.x = sin(window.get_current_time() * 2.0f);
				light_color.y = sin(window.get_current_time() * 0.7f);
				light_color.z = sin(window.get_current_time() * 1.3f);

				glm::vec3 diffuse_color = light_color * glm::vec3(0.5f);
				glm::vec3 ambient_color = diffuse_color * glm::vec3(0.2f);

				shader.set_vec3_uniform("light.ambient", ambient_color);
				shader.set_vec3_uniform("light.diffuse", diffuse_color);

				light_shader.set_vec3_uniform("light_color", light_color);
				prev_time = crnt_time;
			}

			camera.update_vectors();
			camera.update_matrices(shader);
			camera.set_model_matrix(shader, cubePosition, glm::vec3(0.5f, 1.0f, 1.0f));
			shader.set_vec3_uniform("viewPos", camera.get_position());
			glDrawArrays(GL_TRIANGLES, 0, 36);
			VAO.unbind();

			light_VAO.bind();
			light_shader.activate();
			camera.update_matrices(light_shader);
			camera.set_model_matrix(light_shader, light_position, glm::vec3(0.5f, 1.0f, 1.0f), 0.0f, glm::vec3(0.5f));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			light_VAO.unbind();

			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}
}