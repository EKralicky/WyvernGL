#pragma once
#include "Wyvern.h"
#include "Core.h"


namespace Wyvern {

	enum class InputType {
		NONE,
		// POLL_MOVEMENT, // Every frame, this event will be dispatched to poll for player movement
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


	struct InputEvent {
		InputType inputType;
		bool isRepeating;

		InputEvent(InputType inputType, bool isRepeating) {
			this->inputType = inputType;
			this->isRepeating = isRepeating;
		}

		bool operator==(const InputEvent& otherPoint) const
		{
			return (this->inputType == otherPoint.inputType && this->isRepeating == otherPoint.isRepeating);
		}

		struct HashFunction
		{
			size_t operator()(const InputEvent& input) const
			{
				size_t xHash = std::hash<InputType>()(input.inputType);
				size_t yHash = std::hash<bool>()(input.isRepeating) << 1;
				return xHash ^ (yHash << 1);
			}
		};
	};

	class UserInput {
	public:
		static bool isKeyPressed(int keycode);
		static bool isMouseButtonDown(int mouseButton);
		static void setKeyBinding(InputType inputType, int keycode);
		static InputType getKeyBinding(int keycode); // Retrieves input type from keycode
		static int getKeyBinding(InputType inputType); // Returns keycode given an input type
		static void removeKeyBinding(InputType inputType);
		static void setDefaultKeyBindings();

		static void addActiveInput(InputEvent input); // Adds an InputEvent to the list of active inputs
		static void removeActiveInput(InputType input); // Removes a corresponding InputEvent based on the containing InputType
		static auto& getActiveInputs() { return m_activeInputs;  }
	private:
		inline static std::map<InputType, int> m_keyMap; // maps input to GLFW (or our own) keycode
		inline static std::unordered_set<InputEvent, InputEvent::HashFunction> m_activeInputs; // Stores a list of InputEvents where the input type bound key should be acted upon
	};
}