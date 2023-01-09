#pragma once
#include "PlayerState.h"

namespace Wyvern {
	class InactiveState : public AliveState {
		virtual void handleInput(Player& player, Input input) override
		{
			switch (input)
			{
			default:
				std::cout << "Handled in InactiveState\n";
			}
		}
	};
}
