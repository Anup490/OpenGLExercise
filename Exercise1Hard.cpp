#include "Headers.h"

namespace Exercise1
{
	struct structColor 
	{
		int R;
		int G;
		int B;
		int A;
	};

	using Color = structColor;
	
	static bool should_decrement = true;
	static Color manipulate_color(Color color);
	static Color incrementRGB(Color color);
	static Color decrementRGB(Color color);
	static float to_zero_to_one_range(int value);

	int hard_problem()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* windowTitle = "OpenGLWindowHardProblem";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, windowTitle, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise1::hard_problem" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, window_width, window_height);
		Color color = { 1, 0, 1, 255 };
		double prevTime = glfwGetTime();
		while (!glfwWindowShouldClose(window))
		{
			double crntTime = glfwGetTime();
			if ((crntTime - prevTime) > 1/60)
			{
				color = manipulate_color(color);
				glClearColor(to_zero_to_one_range(color.R), to_zero_to_one_range(color.G), to_zero_to_one_range(color.B), to_zero_to_one_range(color.A));
				glClear(GL_COLOR_BUFFER_BIT);
				glfwSwapBuffers(window);
			}
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}

	Color manipulate_color(Color color)
	{
		return (should_decrement) ? decrementRGB(color) : incrementRGB(color);
	}

	Color incrementRGB(Color color)
	{
		if (color.R < 255)
		{
			color.R += 1;
		}
		else if (color.G < 255)
		{
			color.G += 1;
		}
		else if (color.B < 255)
		{
			color.B += 1;
		}
		else
		{
			should_decrement = true;
		}
		return color;
	}

	Color decrementRGB(Color color)
	{
		if (color.R > 0)
		{
			color.R -= 1;
		}
		else if (color.G > 0)
		{
			color.G -= 1;
		}
		else if (color.B > 0)
		{
			color.B -= 1;
		}
		else
		{
			should_decrement = false;
		}
		return color;
	}

	float to_zero_to_one_range(int value)
	{
		float floatValue = (float)value;
		return floatValue / 255.0;
	}

}