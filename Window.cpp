#pragma once
#include "Window.h"

Window::Window(const char* title)
{
	initialize_glfw(title);
	initialize_glad();
}

Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::should_stay()
{
	return !glfwWindowShouldClose(window);
}

void Window::run_swapbuffer_eventpoller()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::initialize_glfw(const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	window = glfwCreateWindow(window_width, window_height, title, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Error loading window for " << title << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
}

void Window::initialize_glad()
{
	gladLoadGL();
	glViewport(0, 0, window_width, window_height);
}