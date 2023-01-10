#include "ActiveState.h"
#include "Wyvern/player/Player.h"

namespace Wyvern {

	void ActiveState::handleInput(Player& player, InputEvent input)
	{
		switch (input.inputType)
		{
		case InputType::ENTITY_MOVE_FORWARD:
			player.modifyVelocity(player.getCamera()->getFacingVector());
			break;
		case InputType::ENTITY_MOVE_BACKWARD:
			player.modifyVelocity(-player.getCamera()->getFacingVector());
			break;
		case InputType::ENTITY_STRAFE_LEFT:
			player.modifyVelocity(player.getCamera()->getSideVector());
			break;
		case InputType::ENTITY_STRAFE_RIGHT:
			player.modifyVelocity(-player.getCamera()->getSideVector());
			break;
		case InputType::ENTITY_JUMP:
			player.modifyVelocity(glm::vec3(0.0f, 1.0f, 0.0f));
			break;
		case InputType::ENTITY_CROUCH:
			player.modifyVelocity(glm::vec3(0.0f, -1.0f, 0.0f));
			break;
		default: // If not handled in the current state, "fall through" and handle in the parent state
			AliveState::handleInput(player, input);
		}
		
	}
}



