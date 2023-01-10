#include "AliveState.h"
#include "Wyvern/player/Player.h"

namespace Wyvern {

	void AliveState::handleInput(Player& player, InputEvent input)
	{
		switch (input.inputType)
		{
		default: // If not handled in the current state, "fall through" and handle in the parent state
			std::cout << "Event reached top level state : AliveState and did not get processed!\n";
		}
	}
}