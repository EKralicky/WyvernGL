#pragma once
#include "Wyvern.h"
#include "Wyvern/GameWindow.h"


class Camera {

private:
	// position & facing vectors
	glm::vec3 m_position;
	glm::vec3 m_frontVector;
	glm::vec3 m_upVector;
	glm::vec3 m_rightVector;
	glm::vec3 m_worldUpVector;

	// options
	float m_movementSpeed;
	float m_sensitivity;

	// euler angles
	double m_pitch;
	double m_yaw;

	// Flags & Options
	bool m_canMove = true;
	bool m_firstMouse = true;
	float m_lastXPos = Wyvern::WINDOW_WIDTH / 2.0f;
	float m_lastYPos = Wyvern::WINDOW_HEIGHT / 2.0f;

	void updateCameraVectors();

public:
	Camera(glm::vec3 initPos, float sensitivity);
	~Camera();
	glm::mat4 getViewMatrix();
	void processKeyInput(int key, float deltaTime);
	void processMouseInput(float xoffset, float yoffset);

	// Getters & Setters
	inline void  movementSpeed(const float& speed) {
		m_movementSpeed = speed;
	};
	inline float* movementSpeed() {
		return &m_movementSpeed;
	};
	inline void  position(glm::vec3 newPosition) {
		m_position = newPosition;
	}
	inline glm::vec3& position() {
		return m_position;
	}
	inline void  canMove(bool value) {
		m_canMove = value;
	}
	inline bool  canMove() {
		return m_canMove;
	}
	inline void  firstMouse(bool value) {
		m_firstMouse = value;
	}
	inline bool  firstMouse() {
		return m_firstMouse;
	}
	inline void  lastXPos(float pos) {
		m_lastXPos = pos;
	}
	inline float lastXPos() {
		return m_lastXPos;
	}
	inline void  lastYPos(float pos) {
		m_lastYPos = pos;
	}
	inline float lastYPos() {
		return m_lastYPos;
	}
};
