#pragma once
#include "Headers.h"
#include "BaseCamera.h"
#include "Window.h"
#include <vector>

class CameraHandler
{
	static std::vector<BaseCamera*>* pcameras;
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xpos, double ypos);
public:
	CameraHandler(Window& window);
	~CameraHandler();
	void add_camera(BaseCamera* camera);
};