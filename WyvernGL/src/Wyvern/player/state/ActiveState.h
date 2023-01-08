#pragma once
#include "Wyvern/UserInput.h"
#include "AliveState.h"

namespace Wyvern {
	class ActiveState : public AliveState {
	public:
		virtual void handleInput(Player& player, Input input) override
		{
			switch (input)
			{
			case Input::POLL_MOVEMENT:
				if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_MOVE_FORWARD)))
					// move forward
				if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_MOVE_BACKWARD)))
					// move backward
				if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_STRAFE_LEFT)))
					// strafe left
				if (UserInput::isKeyPressed(UserInput::getKeyBinding(Input::ENTITY_STRAFE_RIGHT)))
					// strafe right
				break;
			case Input::ENTITY_MOVE_FORWARD:
				//player.modifyVelocity(player.getCamera()->getFacingVector());
				std::cout << "[ActiveState] MOVE_FORWARD\n";
				break;
			case Input::ENTITY_MOVE_BACKWARD:
				std::cout << "[ActiveState] MOVE_BACKWARD\n";
				break;
			case Input::ENTITY_STRAFE_LEFT:
				std::cout << "[ActiveState] STRAFE_LEFT\n";
				break;
			case Input::ENTITY_STRAFE_RIGHT:
				std::cout << "[ActiveState] STRAFE_RIGHT\n";
				break;
			case Input::ENTITY_JUMP:
				std::cout << "[ActiveState] JUMP\n";
				//player.changeState(PlayerState::jumpingState);
				//player.jump();
				break;

			// If not handled in the current state, "fall through" and handle in the
			// parent state
			default:
				AliveState::handleInput(player, input);
			}
		}


	};

}
