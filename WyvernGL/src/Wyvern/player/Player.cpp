#include "Player.h"
#include "glm/gtx/string_cast.hpp"

namespace Wyvern {

	Player::Player()
		: m_state(&Player::activeState), m_velocity(glm::vec3(0.0f, 0.0f, 0.0f))
	{ 
		m_playerCamera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), 0.1f); // Starting at x y z = 0 0 0, with sensitivity of 0.1
	}

	Player::~Player()
	{ 
		delete m_playerCamera;
	}

	void Player::handleInput(InputAction input)
	{
		m_state->handleInput(*this, input);
	}

	// When we change state, we call exit on the current state, change the state,
	// and call enter on the new state
	void Player::changeState(PlayerState& newState)
	{
		m_state->exit(*this);
		m_state = &newState;
		m_state->enter(*this);
	}

	PlayerState& Player::getState()
	{
		return *m_state;
	}



	void Player::modifyVelocity(glm::vec3 value)
	{
		m_velocity += value;
		/*float minSpeed = -1.0f;
		float maxSpeed = 1.0f;
		m_velocity.x = std::clamp(m_velocity.x += value.x, minSpeed, maxSpeed) + 0.0f;
		m_velocity.y = std::clamp(m_velocity.y += value.y, minSpeed, maxSpeed) + 0.0f;
		m_velocity.z = std::clamp(m_velocity.z += value.z, minSpeed, maxSpeed) + 0.0f;
		std::cout << "VEL" << glm::to_string(m_velocity) << "\n\n";*/
	}

	void Player::decreaseVelocity(float rate)
	{
		m_velocity = glm::vec3(0.0f, 0.0f, 0.0f);
		/*std::cout << "CURR" << glm::to_string(m_velocity) << "\n";
		float x = m_velocity.x == 0 ? 0 : ((-1.0f * sgn(m_velocity.x)) * rate);
		float y = m_velocity.y == 0 ? 0 : ((-1.0f * sgn(m_velocity.y)) * rate);
		float z = m_velocity.z == 0 ? 0 : ((-1.0f * sgn(m_velocity.z)) * rate);
		std::cout << "DEC" << glm::to_string(glm::vec3(x, y, z)) << "\n";
		modifyVelocity(glm::vec3(x, y, z));*/
	}

	void Player::updateCamera()
	{
		m_playerCamera->moveBy(m_velocity);
	}
}
 

