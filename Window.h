#pragma once
#include "Headers.h"

class Window
{
	GLFWwindow* window;
	void initialize_glfw(const char* title);
	void initialize_glad();
public:
	Window(const char* title);
	~Window();
	bool should_stay();
	void run_swapbuffer_eventpoller();
};