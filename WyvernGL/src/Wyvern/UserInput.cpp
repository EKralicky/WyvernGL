#include "UserInput.h"
#include "Application.h"

bool Wyvern::UserInput::isKeyPressed(int key)
{
	return glfwGetKey(Application::get().getWindow().getGLFWWindow(), key) == GLFW_PRESS;
}

bool Wyvern::UserInput::isMouseButtonDown(int mouseButton)
{
	return false;
}
