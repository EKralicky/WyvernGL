#pragma once
#include "PlayerState.h"

namespace Wyvern {
	class DeadState : public PlayerState {
	public:
		virtual void handleInput(Player& player, InputAction input) override;
		STATE_NAME("DeadState")
		STATE_TYPE(DEAD)
	};
}
