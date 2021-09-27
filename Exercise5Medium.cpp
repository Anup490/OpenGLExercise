#include "Wrappers.h"

namespace Exercise5
{
	static int scale_value = 10;
	bool should_decrease = true;
	static void modify_scale_value();

	int medium_problem()
	{
		GLfloat triangle_vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f, sqrt(0.15f), 0.0f,
		};

		const char* window_title = "OpenGLExercise5MediumProblem";
		Window window(window_title);
		VertexBufferObject VBO(triangle_vertices, sizeof(triangle_vertices));
		ShaderProgram shader("exercise5mediumproblem1.vert", "exercise5mediumproblem1.frag");
		VertexArrayObject VAO;
		VAO.link_VBO_data(VBO, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		double prev_time = window.get_current_time();
		while (window.should_stay())
		{
			glClearColor(0.96f, 0.87f, 0.58f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			shader.activate();
			shader.set_float_uniform("scale", clamp_within_one_two(0.0f, scale_value, 10.0f));
			double crnt_time = window.get_current_time();
			if ((crnt_time - prev_time) > 1)
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
		if (should_decrease)
		{
			if (scale_value == 0)
			{
				scale_value++;
				should_decrease = false;
			}
			else
			{
				scale_value--;
			}
		}
		else
		{
			if (scale_value == 10)
			{
				scale_value--;
				should_decrease = true;
			}
			else
			{
				scale_value++;
			}
		}
	}
}

