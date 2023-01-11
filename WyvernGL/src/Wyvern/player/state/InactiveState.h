#pragma once
#include "AliveState.h"

namespace Wyvern {
	class InactiveState : public AliveState {
		virtual void handleInput(Player& player, InputAction input) override;
		virtual void enter(Player& player) override;
		STATE_NAME("InactiveState")
		STATE_TYPE(INACTIVE)
	};
}
