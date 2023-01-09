#pragma once
#include "PlayerState.h"


namespace Wyvern {
	class DeadState : public PlayerState {
		virtual void handleInput(Player& player, Input input) override
		{
			switch (input)
			{
			default:
				std::cout << "Handled in DeadState\n";
			}
		}
	};
}
