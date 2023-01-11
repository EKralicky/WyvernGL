#include "UserInput.h"
#include "Wyvern/Application.h"


namespace Wyvern {

	void UserInput::addKeyBinding(InputAction action, int keycode)
	{
		auto it = m_keyBindings.find(action);
		if (it != m_keyBindings.end()) {
			it->second = keycode;
		}
		else {
			m_keyBindings.insert({ action, keycode });
		}
	}

	int UserInput::getKeyBinding(InputAction action)
	{
		return m_keyBindings.find(action)->second;
	}

	void UserInput::setKeyState(InputAction action, bool state)
	{
		_setKeyStateImpl(action, state);
	}

	void UserInput::setKeyState(int keycode, bool state)
	{
		_setKeyStateImpl(getKeyBinding(keycode), state);
	}

	void UserInput::_setKeyStateImpl(InputAction action, bool state)
	{
		//WYV_ASSERT((action != InputAction::NONE), "Unable to set key state: Input Action is NONE");
		if (action != InputAction::NONE) { // If not bound to any keycode
			auto key = m_keyMap.find(action);
			if (key != m_keyMap.end()) {
				key->second = state;
			}
			else {
				m_keyMap.insert({ action, state });
			}
		}
	}

	// 0.003ms runtime @intel-i7-9700K
	InputAction UserInput::getKeyBinding(int keycode)
	{
		std::map<InputAction, int>::iterator it;
		it = std::find_if(m_keyBindings.begin(), m_keyBindings.end(), [keycode](const std::pair<InputAction, int>& pair) {
			return pair.second == keycode;
			});
		if (it != m_keyBindings.end()) {
			return it->first;
		}
		else {
			return InputAction::NONE;
		}
	}

	void UserInput::removeKeyBinding(InputAction action)
	{
		m_keyBindings.erase(m_keyBindings.find(action));
	}

	void UserInput::setDefaultKeyBindings()
	{
		addKeyBinding(InputAction::ENTITY_MOVE_FORWARD, WYV_KEY_W);
		addKeyBinding(InputAction::ENTITY_MOVE_BACKWARD, WYV_KEY_S);
		addKeyBinding(InputAction::ENTITY_STRAFE_LEFT, WYV_KEY_A);
		addKeyBinding(InputAction::ENTITY_STRAFE_RIGHT, WYV_KEY_D);
		addKeyBinding(InputAction::ENTITY_JUMP, WYV_KEY_SPACE);
		addKeyBinding(InputAction::ENTITY_CROUCH, WYV_KEY_LEFT_CONTROL);
		addKeyBinding(InputAction::ENTITY_SPRINT, WYV_KEY_LEFT_SHIFT);
		addKeyBinding(InputAction::ENTITY_OPEN_INVENTORY, WYV_KEY_LEFT_SHIFT);
		addKeyBinding(InputAction::ESCAPE, WYV_KEY_ESCAPE);
		addKeyBinding(InputAction::OPEN_DEBUG_MENU, WYV_KEY_GRAVE_ACCENT);
		addKeyBinding(InputAction::VIEW_ONLINE_PLAYERS, WYV_KEY_TAB);
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








