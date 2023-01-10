#pragma once
#include "AliveState.h"

namespace Wyvern {
	class InactiveState : public AliveState {
		virtual void handleInput(Player& player, InputEvent input) override;
		STATE_NAME("InactiveState")
		STATE_TYPE(INACTIVE)
	};
}
