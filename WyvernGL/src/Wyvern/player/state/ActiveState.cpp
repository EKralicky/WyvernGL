#include "ActiveState.h"
#include "Wyvern/player/Player.h"
#include "Wyvern/Application.h"

namespace Wyvern {

	void ActiveState::handleInput(Player& player, InputAction input)
	{
		switch (input)
		{
		case InputAction::ENTITY_MOVE_FORWARD:
			player.modifyVelocity(player.getCamera()->getFacingVector());
			break;
		case InputAction::ENTITY_MOVE_BACKWARD:
			player.modifyVelocity(-player.getCamera()->getFacingVector());
			break;
		case InputAction::ENTITY_STRAFE_LEFT:
			player.modifyVelocity(-player.getCamera()->getSideVector());
			break;
		case InputAction::ENTITY_STRAFE_RIGHT:
			player.modifyVelocity(player.getCamera()->getSideVector());
			break;
		case InputAction::ENTITY_JUMP:
			player.modifyVelocity(glm::vec3(0.0f, 1.0f, 0.0f));
			break;
		case InputAction::ENTITY_CROUCH:
			player.modifyVelocity(glm::vec3(0.0f, -1.0f, 0.0f));
			break;
		case InputAction::OPEN_DEBUG_MENU:
			UserInput::setKeyState(input, false); // Executes once
			player.changeState(Player::inactiveState);
			break;
		default: // If not handled in the current state, "fall through" and handle in the parent state
			AliveState::handleInput(player, input);
		}
	}
}



