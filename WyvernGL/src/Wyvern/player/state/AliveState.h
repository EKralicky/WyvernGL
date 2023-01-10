#pragma once
#include "PlayerState.h"

namespace Wyvern {
	class AliveState : public PlayerState {
	public:
		virtual void handleInput(Player& player, InputEvent input) override;
		STATE_NAME("AliveState")
		STATE_TYPE(ALIVE)
	};
}
