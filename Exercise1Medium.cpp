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
		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0,0,windowWidth,windowHeight);
		bool isColorWhite = false;
		while (!glfwWindowShouldClose(window))
		{
			if (isColorWhite) {
				glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
				isColorWhite = false;
			}
			else
			{
				glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
				isColorWhite = true;
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
