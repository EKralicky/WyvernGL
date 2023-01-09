#pragma once
#include "Wyvern/UserInput.h"

namespace Wyvern {
	class Player;
	class PlayerState {
	public:
		virtual ~PlayerState() {}
		virtual void handleInput(Player& player, Input input) = 0;
		virtual void enter(Player& player) {}
		virtual void exit(Player& player) {}

		//virtual const char* getStateName() { return "None"; }
	};

//#define STATE_NAME(name) virtual const char* getStatename() const { return #name; }

}

