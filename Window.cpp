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

double Window::get_current_time()
{
	return glfwGetTime();
}

bool Window::has_pressed(int key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}

void Window::activate_mouse_input(function mouse_callback, function scroll_callback)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
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