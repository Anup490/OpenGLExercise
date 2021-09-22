#include "Headers.h"

namespace Exercise1 {
	int easy_problem_1()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* windowTitle = "OpenGLExercise1EasyProblem 1";
		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for easy_problem_1" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, windowWidth, windowHeight);
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
		int windowWidth = 400;
		int windowHeight = 225;
		const char* windowTitle = "OpenGLExercise1EasyProblem 2";
		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for easy_problem_2" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, windowWidth, windowHeight);
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
		const char* windowTitle = "OpenGLExercise1EasyProblem 3 I made this!";
		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Error loading window for easy_problem_3" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glViewport(0, 0, windowWidth, windowHeight);
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

