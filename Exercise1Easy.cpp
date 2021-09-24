#include "Headers.h"

namespace Exercise1 {
	int easy_problem_1()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* window_title = "OpenGLExercise1EasyProblem 1";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise1::easy_problem_1" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, window_width, window_height);
		glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}

	int easy_problem_2()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		int window_width = 400;
		int window_height = 225;
		const char* window_title = "OpenGLExercise1EasyProblem 2";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise1::easy_problem_2" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, window_width, window_height);
		glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}

	int easy_problem_3()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* window_title = "OpenGLExercise1EasyProblem 3 I made this!";
		GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for Exercise1::easy_problem_3" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, window_width, window_height);
		glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}
}

