#pragma once
#include "Wyvern.h"
#include "Core.h"


namespace Wyvern {

	enum class Input {
		NONE,
		POLL_MOVEMENT, // Every frame, this event will be dispatched to poll for player movement
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
		inline static std::map<Input, int> keyMap; // maps input to GLFW (or our own) keycode
		static bool isKeyPressed(int keycode);
		static bool isMouseButtonDown(int mouseButton);
		static void setKeyBinding(Input inputType, int keycode);
		static Input getKeyBinding(int keycode); // Retrieves input type from keycode
		static int getKeyBinding(Input inputType); // Returns keycode given an input type
		static void removeKeyBinding(Input inputType);
		static void setDefaultKeyBindings();
	};
}