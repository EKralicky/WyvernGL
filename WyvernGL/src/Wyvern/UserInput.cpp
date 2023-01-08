#include "UserInput.h"
#include "Application.h"


namespace Wyvern {

	void UserInput::setKeyBinding(Input inputType, int keycode)
	{
		UserInput::keyMap.insert_or_assign(inputType, keycode);
	}

	void UserInput::removeKeyBinding(Input inputType)
	{
		UserInput::keyMap.insert_or_assign(inputType, GLFW_KEY_UNKNOWN);
	}

	void UserInput::setDefaultKeyBindings()
	{
		setKeyBinding(Input::ENTITY_MOVE_FORWARD, GLFW_KEY_W);
		setKeyBinding(Input::ENTITY_MOVE_BACKWARD, GLFW_KEY_S);
		setKeyBinding(Input::ENTITY_STRAFE_LEFT, GLFW_KEY_A);
		setKeyBinding(Input::ENTITY_STRAFE_RIGHT, GLFW_KEY_D);
		setKeyBinding(Input::ENTITY_JUMP, GLFW_KEY_SPACE);
		setKeyBinding(Input::ENTITY_CROUCH, GLFW_KEY_LEFT_CONTROL);
		setKeyBinding(Input::ENTITY_SPRINT, GLFW_KEY_LEFT_SHIFT);
		setKeyBinding(Input::ENTITY_OPEN_INVENTORY, GLFW_KEY_LEFT_SHIFT);

		setKeyBinding(Input::ESCAPE, GLFW_KEY_ESCAPE);
		setKeyBinding(Input::OPEN_DEBUG_MENU, GLFW_KEY_GRAVE_ACCENT);
		setKeyBinding(Input::VIEW_ONLINE_PLAYERS, GLFW_KEY_TAB);
	}

	bool UserInput::isKeyPressed(int key)
	{
		return glfwGetKey(Application::get().getWindow().getGLFWWindow(), key) == GLFW_PRESS;
	}

	bool UserInput::isMouseButtonDown(int mouseButton)
	{
		return false;
	}

}








