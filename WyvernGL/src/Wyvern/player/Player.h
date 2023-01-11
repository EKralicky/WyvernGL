#pragma once
#include "Wyvern.h"
#include "state/ActiveState.h"
#include "state/InactiveState.h"
#include "state/AliveState.h"
#include "state/DeadState.h"
#include "Wyvern/render/Camera.h"
#include "Wyvern/player/state/PlayerState.h"

namespace Wyvern {

	// This class is eventually going to inherit RidgidBody for physics calculations
	class Player {
	private:
		Camera* m_playerCamera;
		// I have no idea how im going to store coordinates right now so ill add these here
		glm::vec3 m_worldCoordinates;
		glm::vec3 m_chunkCoordinates; 
		int m_healthPoints;
		PlayerState* m_state;
		glm::vec3 m_velocity; // Temporary physics. Remove when RigidBody is added
		float m_maxVelocity; // Velocity multiplier. defulated to glm::vec3(1.0f, 1.0f, 1.0f)
		
	public:
		Player();
		~Player();

		inline static ActiveState activeState;
		inline static InactiveState inactiveState;
		inline static AliveState aliveState;
		inline static DeadState deadState;

		Camera* getCamera() { return m_playerCamera; }

		void handleInput(InputAction input); // Dispatches to player state machine
		void changeState(PlayerState& state);
		PlayerState& getState();
		void modifyVelocity(glm::vec3 value);
		void decreaseVelocity(float rate);
		void updateCamera();
		inline void setMaxVelocity(float maxVel) { m_maxVelocity = maxVel; }
		// returns by ptr
		inline float* getMaxVelocity() { return &m_maxVelocity; }

	};

}
