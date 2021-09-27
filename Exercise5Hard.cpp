#include "Wrappers.h"

namespace Exercise5
{
	static float scale_value = 1.0f;
	static bool should_increase = false;
	static void modify_scale_value();

	int hard_problem()
	{
		GLfloat triangle_vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f, sqrt(0.15f), 0.0f,
		};

		const char* window_title = "OpenGLExercise5HardProblem";
		Window window(window_title);
		VertexBufferObject VBO(triangle_vertices, sizeof(triangle_vertices));
		ShaderProgram shader("exercise5hardproblem1.vert", "exercise5hardproblem1.frag");
		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		double prev_time = window.get_current_time();
		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			shader.activate();
			shader.set_float_uniform("scale", sin(scale_value));
			double crnt_time = window.get_current_time();
			if ((crnt_time - prev_time) > 0.1f)
			{
				modify_scale_value();
				prev_time = crnt_time;
			}
			glDrawArrays(GL_TRIANGLES, 0, 3);
			window.run_swapbuffer_eventpoller();
		}
		return 0;
	}

	void modify_scale_value()
	{
		if (should_increase)
		{
			scale_value = 1.0f;
			should_increase = false;
		}
		else
		{
			scale_value = 0.9f;
			should_increase = true;
		}
	}
}