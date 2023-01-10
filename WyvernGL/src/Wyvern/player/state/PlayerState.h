#pragma once
#include "Wyvern/input/UserInput.h"

namespace Wyvern {
	class Player;

	enum class PlayerStateType {
		NONE,

		ALIVE,
		DEAD,
		ACTIVE,
		INACTIVE,
	};

#define STATE_NAME(name) virtual const char* getStateName() const override { return #name; }
#define STATE_TYPE(name) virtual PlayerStateType getStateType() const override { return PlayerStateType::name; }

	class PlayerState {
	public:
		virtual ~PlayerState() {}
		virtual void handleInput(Player& player, InputEvent input) = 0;
		virtual void enter(Player& player) {}
		virtual void exit(Player& player) {}

		virtual const char* getStateName() const { return "None"; }
		virtual PlayerStateType getStateType() const { return PlayerStateType::NONE; }
	};
}

