#pragma once
#include "PlayerState.h"


namespace Wyvern {
	class DeadState : public PlayerState {
		virtual void handleInput(Player& player, InputEvent input) override;
		STATE_NAME("DeadState")
		STATE_TYPE(DEAD)
	};
}
