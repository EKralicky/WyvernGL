#pragma once
#include "Wyvern/UserInput.h"
#include "AliveState.h"

namespace Wyvern {
	class Player;
	class ActiveState : public AliveState {
	public:
		virtual void handleInput(Player& player, Input input) override;
	};

}
