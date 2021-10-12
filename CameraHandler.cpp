#include "CameraHandler.h"

std::vector<BaseCamera*>* CameraHandler::pcameras = 0;
CameraHandler::CameraHandler(Window& window)
{
	pcameras = new std::vector<BaseCamera*>();
	window.activate_mouse_input(mouse_callback, scroll_callback);
}

CameraHandler::~CameraHandler()
{
	delete pcameras;
}

void CameraHandler::add_camera(BaseCamera* camera)
{
	pcameras->push_back(camera);
}

void CameraHandler::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	for (int i=0; i<pcameras->size(); i++)
	{
		pcameras->at(i)->mouse_callback(window, xpos, ypos);
	}
}

void CameraHandler::scroll_callback(GLFWwindow* window, double xpos, double ypos)
{
	for (int i = 0; i < pcameras->size(); i++)
	{
		pcameras->at(i)->scroll_callback(window, xpos, ypos);
	}
}

	