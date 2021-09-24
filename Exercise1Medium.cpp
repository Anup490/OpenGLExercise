#include "Headers.h"
#include <thread>        
#include <chrono>  

namespace Exercise1
{
	int medium_problem()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* windowTitle = "OpenGLWindowMediumProblem";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, windowTitle, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise1::medium_problem" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0,0,window_width,window_height);
		bool is_color_white = false;
		while (!glfwWindowShouldClose(window))
		{
			if (is_color_white) {
				glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
				is_color_white = false;
			}
			else
			{
				glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
				is_color_white = true;
			}
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			glfwPollEvents();
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}
}

