#include "Player.h"


namespace Wyvern {

	Player::Player()
		: m_state(Player::activeState)
	{ 
		//m_playerCamera = new Camera(glm::vec3(0, 0, 0), 0.1f); // Starting at x y z = 0 0 0, with sensitivity of 0.1
	}

	Player::~Player()
	{ }

	void Player::update()
	{
		
	}

	void Player::handleInput(Input input)
	{
		m_state.handleInput(*this, input);
	}

	// When we change state, we call exit on the current state, change the state,
	// and call enter on the new state
	void Player::changeState(PlayerState& newState)
	{
		m_state.exit(*this);
		m_state = newState;
		m_state.enter(*this);
	}
}
 

