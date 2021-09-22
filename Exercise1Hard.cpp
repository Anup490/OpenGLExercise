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
	static Color manipulate_color(Color color);
	static float to_zero_to_one_range(int value);

	int hard_problem()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* windowTitle = "OpenGLWindowHardProblem";
		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for hard_problem" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, windowWidth, windowHeight);
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
		Color newColor = color;
		if ((color.R >= 0) && (color.R < 255) && (color.G >= 0) && (color.G < 255) && (color.B == 0))
		{
			++newColor.R;
		}
		else if ((color.R > 0) && (color.R <= 255) && (color.G >= 0) && (color.G < 255) && (color.B >= 0) && (color.B < 255))
		{
			++newColor.G;
		}
		else if ((color.R > 0) && (color.R <= 255) && (color.G > 0) && (color.G <= 255) && (color.B >= 0) && (color.B < 255))
		{
			++newColor.B;
		}
		else if ((color.R > 0) && (color.R <= 255) && (color.G > 0) && (color.G <= 255) && (color.B > 0) && (color.B <= 255) )
		{
			--newColor.R;
		}
		else if ((color.R >= 0) && (color.R < 255) && (color.G > 0) && (color.G <= 255) && (color.B > 0) && (color.B <= 255))
		{
			--newColor.G;
		}
		else if ((color.R >= 0) && (color.R < 255) && (color.G >= 0) && (color.G < 255) && (color.B > 0) && (color.B <= 255))
		{
			--newColor.B;
		}
		return newColor;
	}

	float to_zero_to_one_range(int value)
	{
		float floatValue = (float)value;
		return floatValue / 255.0;
	}

}