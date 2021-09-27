#include "Wrappers.h"

namespace Exercise5
{
	int easy_problem_1()
	{
		GLfloat triangle_vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f, sqrt(0.15f), 0.0f,
		};
		const char* window_title = "OpenGLExercise5EasyProblem 1";
		Window window(window_title);
		VertexBufferObject VBO(triangle_vertices, sizeof(triangle_vertices));
		ShaderProgram shader("easyproblem1.vert","easyproblem1.frag");
		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			shader.activate();
			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}

	int easy_problem_2()
	{
		GLfloat triangle_vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f, sqrt(0.15f), 0.0f,
		};
		const char* window_title = "OpenGLExercise5EasyProblem 2";
		Window window(window_title);
		VertexBufferObject VBO(triangle_vertices, sizeof(triangle_vertices));
		ShaderProgram shader("easyproblem2.vert", "easyproblem2.frag");
		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			shader.activate();
			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}
}