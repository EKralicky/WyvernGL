#pragma once
#include "Wyvern.h"
#include "Wyvern/player/state/ActiveState.h"
#include "Wyvern/render/Camera.h"

namespace Wyvern {

	class Player;
	class PlayerState {
	public:
		static ActiveState activeState;

		virtual ~PlayerState() {}
		virtual void handleInput(Player& player, Input input) {}
		virtual void update(Player& player) {}
		virtual void enter(Player& player) {}
		virtual void exit(Player& player) {}
	};

	// This class is eventually going to inherit RidgidBody for physics calculations
	class Player {
	
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

		void update();
		void handleInput(Input input); // Dispatches to player state machine
		void changeState(PlayerState& state);
		void modifyVelocity(glm::vec3 value) { 
			m_velocity += value;
			if (m_velocity.x > m_maxVelocity.x) {
				m_velocity.x = m_maxVelocity.x;
			}
			if (m_velocity.y > m_maxVelocity.y) {
				m_velocity.y = m_maxVelocity.y;
			}
			if (m_velocity.z > m_maxVelocity.z) {
				m_velocity.z = m_maxVelocity.z;
			}
		}
	};




}
