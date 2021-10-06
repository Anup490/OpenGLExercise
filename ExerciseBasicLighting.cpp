#include "Wrappers.h"

namespace ExerciseBasicLighting
{
	int problem1()
	{
		GLfloat square_vertices[] =
		{
			//VERTICES            TEXCOORDS        NORMALS
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f, 1.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
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

		const char* window_title = "OpenGLExerciseBasicLighting 1";
		Window window(window_title);

		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exercisebasiclighting1.vert", "exercisebasiclighting1.frag");
		shader.set_int_uniform("tex0", 0);
		shader.set_int_uniform("tex1", 1);
		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		VAO.link_VBO_data(VBO, 2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

		VertexBufferObject light_VBO(light_vertices, sizeof(light_vertices));
		ShaderProgram light_shader("light.vert", "light.frag");
		VertexArrayObject light_VAO;
		light_VAO.link_VBO_data(light_VBO, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

		Texture tex1("happy.png", GL_TEXTURE0, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGBA);
		Texture tex2("container.png", GL_TEXTURE1, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGB);

		glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 camera_target = glm::vec3(0.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		Camera camera(window, camera_pos, camera_target, up);
		camera.set_view_matrix(shader);
		camera.set_projection_matrix(shader);
		camera.set_view_matrix(light_shader);
		camera.set_projection_matrix(light_shader);

		glm::vec3 light_color(1.0f);
		shader.set_vec3_uniform("lightColor", light_color);
		shader.set_vec3_uniform("lightPos", light_position);

		bool should_inc_x = false;
		float prev_time = window.get_current_time();
		float crnt_time;

		glEnable(GL_DEPTH_TEST);

		while (window.should_stay())
		{
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			VAO.bind();
			shader.activate();
			crnt_time = window.get_current_time();
			if ((crnt_time - prev_time) > 0.5f)
			{
				light_position.x += cos(crnt_time);
				shader.set_vec3_uniform("lightPos", light_position);
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