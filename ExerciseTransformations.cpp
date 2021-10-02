#include "Wrappers.h"

namespace ExerciseTransformations
{
	int problem1()

	{
		GLfloat square_vertices[] =
		{
			//   COORDINATES       TEXCOORDS
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
			-0.5f,  0.5f, 0.0f,   0.0f, 1.0f,
			 0.5f,  0.5f, 0.0f,   1.0f, 1.0f
		};

		GLuint square_indices[] =
		{
			0, 1, 2,
			2, 3, 1
		};

		const char* window_title = "OpenGLExerciseTransformations 1";
		Window window(window_title);
		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exercisetransformations.vert", "exercisetransformations.frag");
		shader.set_int_uniform("tex0", 0);
		shader.set_int_uniform("tex1", 1);

		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		ElementBufferObject EBO(square_indices, sizeof(square_indices));

		Texture tex1("happy.png", GL_TEXTURE0, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGBA);
		Texture tex2("container.png", GL_TEXTURE1, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGB);

		glm::mat4 trans_matrix = glm::mat4(1.0f);
		trans_matrix = glm::rotate(trans_matrix, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
		trans_matrix = glm::translate(trans_matrix, glm::vec3(0.5f, -0.5f, 0.0f));
		trans_matrix = glm::scale(trans_matrix, glm::vec3(0.5, 0.5, 0.5));
		shader.set_mat4_uniform("transform", trans_matrix);

		float prev_time = window.get_current_time();
		float crnt_time;
		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			crnt_time = window.get_current_time();
			if ((crnt_time - prev_time) > 0.05f)
			{
				trans_matrix = glm::rotate(trans_matrix, glm::radians(1.0f), glm::vec3(0.0, 0.0, 1.0));
				shader.set_mat4_uniform("transform", trans_matrix);
				prev_time = crnt_time;
			}

			VAO.bind(EBO);
			shader.activate();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}

	int problem2()

	{
		GLfloat square_vertices[] =
		{
			//   COORDINATES       TEXCOORDS
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
			-0.5f,  0.5f, 0.0f,   0.0f, 1.0f,
			 0.5f,  0.5f, 0.0f,   1.0f, 1.0f
		};

		GLuint square_indices[] =
		{
			0, 1, 2,
			2, 3, 1
		};

		const char* window_title = "OpenGLExerciseTransformations 1";
		Window window(window_title);
		VertexBufferObject VBO(square_vertices, sizeof(square_vertices));
		ShaderProgram shader("exercisetransformations.vert", "exercisetransformations.frag");
		shader.set_int_uniform("tex0", 0);
		shader.set_int_uniform("tex1", 1);

		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		VAO.link_VBO_data(VBO, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		ElementBufferObject EBO(square_indices, sizeof(square_indices));

		Texture tex1("happy.png", GL_TEXTURE0, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGBA);
		Texture tex2("container.png", GL_TEXTURE1, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR, GL_RGB);

		glm::mat4 trans_matrix = glm::mat4(1.0f);
		trans_matrix = glm::translate(trans_matrix, glm::vec3(0.5f, -0.5f, 0.0f));
		trans_matrix = glm::rotate(trans_matrix, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
		trans_matrix = glm::scale(trans_matrix, glm::vec3(0.5, 0.5, 1.0));


		glm::mat4 trans_matrix_2 = glm::mat4(1.0f);
		trans_matrix_2 = glm::translate(trans_matrix_2, glm::vec3(-0.5f, 0.5f, 0.0f));
		trans_matrix_2 = glm::rotate(trans_matrix_2, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
		trans_matrix_2 = glm::scale(trans_matrix_2, glm::vec3(0.5, 0.5, 0.5));

		
		float prev_time = window.get_current_time();
		float crnt_time;
		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			crnt_time = window.get_current_time();
			if ((crnt_time - prev_time) > 0.05f)
			{
				trans_matrix = glm::rotate(trans_matrix, glm::radians(1.0f), glm::vec3(0.0, 0.0, 1.0));
				trans_matrix_2 = glm::mat4(1.0f);
				trans_matrix_2 = glm::translate(trans_matrix_2, glm::vec3(-0.5f, 0.5f, 0.0f));
				float scalar = (sin(crnt_time) < 0.0f)?sin(crnt_time) * -1.0f: sin(crnt_time);
				trans_matrix_2 = glm::scale(trans_matrix_2, glm::vec3(scalar, scalar, 1.0));
				prev_time = crnt_time;
			}
			VAO.bind(EBO);
			shader.activate();

			shader.set_mat4_uniform("transform", trans_matrix_2);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			shader.set_mat4_uniform("transform", trans_matrix);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}


}