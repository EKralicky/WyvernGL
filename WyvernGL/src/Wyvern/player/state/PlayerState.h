#pragma once
#include "Wyvern/input/UserInput.h"

namespace Wyvern {

	class Player;
	enum class PlayerStateType {
		NONE = 0,
		ALIVE,
		DEAD,
		ACTIVE,
		INACTIVE,
	};

#define STATE_NAME(name) virtual const char* getName() const override { return #name; }
#define STATE_TYPE(name) virtual PlayerStateType getType() const override { return PlayerStateType::name; }

	class PlayerState {
	public:
		virtual ~PlayerState() {}
		virtual void handleInput(Player& player, InputAction input) = 0;
		virtual void enter(Player& player) {}
		virtual void exit(Player& player) {}

		virtual const char* getName() const { return "None"; }
		virtual PlayerStateType getType() const { return PlayerStateType::NONE; }
	};
}

