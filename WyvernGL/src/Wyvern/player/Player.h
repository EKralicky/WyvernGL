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

		inline static ActiveState activeState;
		inline static AliveState aliveState;

	private:
		Camera* m_playerCamera;
		// I have no idea how im going to store coordinates right now so ill add these here
		glm::vec3 m_worldCoordinates;
		glm::vec3 m_chunkCoordinates; 
		int m_healthPoints;
		PlayerState& m_state;
		glm::vec3 m_velocity; // Temporary physics. Remove when RigidBody is added
		glm::vec3 m_maxVelocity; // Basically the movement speed
		
	public:
		Player();
		~Player();

		Camera* getCamera() { return m_playerCamera; }

		void handleInput(Input input); // Dispatches to player state machine
		void changeState(PlayerState& state);
		void modifyVelocity(glm::vec3 value);
		void decreaseVelocity(float rate);
		void updateCamera();

	};
}
