#pragma once
#include "AliveState.h"

namespace Wyvern {
	class Player;
	class ActiveState : public AliveState {
	public:
		virtual void handleInput(Player& player, InputEvent input) override;
		STATE_NAME("ActiveState")
		STATE_TYPE(ACTIVE)
	};
}


