#pragma once
#include "Headers.h"

class Window
{
	using function = void(GLFWwindow* window, double xpos, double ypos);

	GLFWwindow* window;
	void initialize_glfw(const char* title);
	void initialize_glad();
public:
	Window(const char* title);
	~Window();
	bool should_stay();
	void run_swapbuffer_eventpoller();
	double get_current_time();
	bool has_pressed(int key);
	void activate_mouse_input(function mouse_callback, function scroll_callback);
};