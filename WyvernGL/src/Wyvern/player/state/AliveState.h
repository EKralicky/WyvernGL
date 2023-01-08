#pragma once
#include "PlayerState.h"

namespace Wyvern {

	class AliveState : public PlayerState {
	public:
		virtual void handleInput(Player& player, Input input) override
		{
			switch (input)
			{
			default:
				std::cout << "beans\n";
			}
		}

	};
}
