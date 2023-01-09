#pragma once
#include "Wyvern/UserInput.h"

namespace Wyvern {
	class Player;
	class PlayerState {
	public:
		virtual ~PlayerState() {}
		virtual void handleInput(Player& player, Input input) {}
		virtual void update(Player& player) {}
		virtual void enter(Player& player) {}
		virtual void exit(Player& player) {}
	};
}

