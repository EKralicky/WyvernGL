#pragma once
#include "Wyvern.h"
#include "Core.h"


namespace Wyvern {

	enum class Input {
		// Entity Specific
		ENTITY_JUMP,
		ENTITY_CROUCH,
		ENTITY_SPRINT,
		ENTITY_MOVE_FORWARD,
		ENTITY_MOVE_BACKWARD,
		ENTITY_STRAFE_LEFT,
		ENTITY_STRAFE_RIGHT,
		ENTITY_OPEN_INVENTORY,
		// User Specific
		ESCAPE,
		OPEN_DEBUG_MENU,
		VIEW_ONLINE_PLAYERS
	};


	class UserInput {
	public:
		static std::map<Input, int>& keyMap; // maps input to GLFW (or our own) keycode
		static bool isKeyPressed(int keycode);
		static bool isMouseButtonDown(int mouseButton);
		static void setKeyBinding(Input inputType, int keycode);
		static void removeKeyBinding(Input inputType);
		static void setDefaultKeyBindings();
	};
}