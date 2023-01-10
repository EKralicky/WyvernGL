#include "UserInput.h"
#include "Application.h"


namespace Wyvern {

	void UserInput::setKeyBinding(InputType inputType, int keycode)
	{
		m_keyMap.insert_or_assign(inputType, keycode);
	}

	InputType UserInput::getKeyBinding(int keycode)
	{
		for (const auto& [key, value] : UserInput::m_keyMap) 
			if (value == keycode)
				return key;
		return InputType::NONE;
	}

	int UserInput::getKeyBinding(InputType inputType)
	{
		return m_keyMap.find(inputType)->second;
	}

	void UserInput::removeKeyBinding(InputType inputType)
	{
		UserInput::m_keyMap.insert_or_assign(inputType, GLFW_KEY_UNKNOWN);
	}

	void UserInput::setDefaultKeyBindings()
	{
		setKeyBinding(InputType::ENTITY_MOVE_FORWARD, GLFW_KEY_W);
		setKeyBinding(InputType::ENTITY_MOVE_BACKWARD, GLFW_KEY_S);
		setKeyBinding(InputType::ENTITY_STRAFE_LEFT, GLFW_KEY_A);
		setKeyBinding(InputType::ENTITY_STRAFE_RIGHT, GLFW_KEY_D);
		setKeyBinding(InputType::ENTITY_JUMP, GLFW_KEY_SPACE);
		setKeyBinding(InputType::ENTITY_CROUCH, GLFW_KEY_LEFT_CONTROL);
		setKeyBinding(InputType::ENTITY_SPRINT, GLFW_KEY_LEFT_SHIFT);
		setKeyBinding(InputType::ENTITY_OPEN_INVENTORY, GLFW_KEY_LEFT_SHIFT);

		setKeyBinding(InputType::ESCAPE, GLFW_KEY_ESCAPE);
		setKeyBinding(InputType::OPEN_DEBUG_MENU, GLFW_KEY_GRAVE_ACCENT);
		setKeyBinding(InputType::VIEW_ONLINE_PLAYERS, GLFW_KEY_TAB);
	}

	void UserInput::addActiveInput(InputEvent input)
	{
		m_activeInputs.insert(input);
	}

	void UserInput::removeActiveInput(InputType input)
	{
		std::cout << "SIZE: " << m_activeInputs.size() << "\n";
		for (auto i = m_activeInputs.begin(), last = m_activeInputs.end(); i != last; ) {
			if (i->inputType == input) {
				i = m_activeInputs.erase(i);
			}
			else {
				++i;
			}
		}
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








