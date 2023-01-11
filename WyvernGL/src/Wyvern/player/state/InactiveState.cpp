#include "InactiveState.h"
#include "Wyvern/player/Player.h"
#include "Wyvern/Application.h"

namespace Wyvern {

	void InactiveState::handleInput(Player& player, InputAction input)
	{
		switch (input) 
		{
		case InputAction::OPEN_DEBUG_MENU:
			UserInput::setKeyState(input, false);
			Application::get().getWindow().setCursorMode(GLFW_CURSOR_DISABLED); // enable cursor
			player.getCamera()->canMove(true); // camera can move
			player.changeState(Player::activeState);
			break;
		default: // If not handled in the current state, "fall through" and handle in the parent state
			AliveState::handleInput(player, input);
		}
	}

	void InactiveState::enter(Player& player) {
		Application::get().getWindow().setCursorMode(GLFW_CURSOR_NORMAL); // disable cursor
		player.getCamera()->canMove(false); // disable camera
		player.getCamera()->firstMouse(true); // idek what this does
	}
}
