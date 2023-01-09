#include "ActiveState.h"
#include "Wyvern/player/Player.h"

void Wyvern::ActiveState::handleInput(Player& player, Input input)
{
	{
		switch (input)
		{
		case Input::POLL_MOVEMENT:
			if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_MOVE_FORWARD)))
				player.modifyVelocity(player.getCamera()->getFacingVector());
			if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_MOVE_BACKWARD)))
				player.modifyVelocity(-player.getCamera()->getFacingVector());
			if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_STRAFE_LEFT)))
				player.modifyVelocity(-player.getCamera()->getSideVector());
			if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_STRAFE_RIGHT)))
				player.modifyVelocity(player.getCamera()->getSideVector());
			if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_JUMP)))
				player.modifyVelocity(glm::vec3(0.0f, 1.0f, 0.0f));
			if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_CROUCH)))
				player.modifyVelocity(glm::vec3(0.0f, -1.0f, 0.0f));
			break;
			// If not handled in the current state, "fall through" and handle in the
			// parent state
		default:
			AliveState::handleInput(player, input);
		}
	}
}
