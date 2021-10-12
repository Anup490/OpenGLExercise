#pragma once
#include "Window.h"

class BaseCamera
{
public:
	virtual void mouse_callback(GLFWwindow* window, double xpos, double ypos) = 0;
	virtual void scroll_callback(GLFWwindow* window, double xpos, double ypos) = 0;
};

