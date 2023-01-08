#include "Camera.h"



Camera::Camera(glm::vec3 initPos, float sensitivity)
	: m_movementSpeed(20.0f)
{
	m_position = initPos;
	m_frontVector = glm::vec3(0.0f, 0.0f, -1.0f);
	m_rightVector = glm::vec3(1.0f, 0.0f, 0.0f); // points at positive x
	m_upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	m_worldUpVector = glm::vec3(0.0f, 1.0f, 0.0f);

	m_pitch = 0.0f;
	m_yaw = -90.0f;

	m_sensitivity = sensitivity;
}


Camera::~Camera()
{
	
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(m_position, m_position + m_frontVector, m_upVector);
}



void Camera::updateCameraVectors()
{
	glm::vec3 front;

	front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	front.y = sin(glm::radians(m_pitch));
	front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

	// Update 3 main camera vectors
	m_frontVector = glm::normalize(front);
	m_rightVector = glm::normalize(glm::cross(m_frontVector, m_worldUpVector));
	m_upVector = glm::normalize(glm::cross(m_rightVector, m_frontVector));

}

// Moves each coordinate of the camera's current position by a certain amount
//void Camera::moveBy(glm::vec3 amount) {
//	m_position 
//}

void Camera::processKeyInput(int key, float deltaTime)
{
	float uniformMovementSpeed = m_movementSpeed * deltaTime;
	if (m_canMove) {
		if (key == GLFW_KEY_W)
			m_position += uniformMovementSpeed * glm::normalize(glm::vec3(m_frontVector.x, 0.0f, m_frontVector.z));
		if (key == GLFW_KEY_S)
			m_position -= uniformMovementSpeed * glm::normalize(glm::vec3(m_frontVector.x, 0.0f, m_frontVector.z));
		if (key == GLFW_KEY_A)
			m_position -= uniformMovementSpeed * glm::normalize(glm::cross(m_frontVector, m_upVector)); // position equals speed * right vector
		if (key == GLFW_KEY_D)
			m_position += uniformMovementSpeed * glm::normalize(glm::cross(m_frontVector, m_upVector));
		if (key == GLFW_KEY_SPACE)
			m_position += uniformMovementSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
		if (key == GLFW_KEY_LEFT_CONTROL)
			m_position -= uniformMovementSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
	}
	
}

void Camera::processMouseInput(float xposd, float yposd)
{
	if (canMove()) { // Is the camera allowed to move?
		float xpos = static_cast<float>(xposd);
		float ypos = static_cast<float>(yposd);

		if (firstMouse()) // Is it the first time that the mouse has moved? This gets set to true when you enter debug mode "~"
		{
			lastXPos(xpos);
			lastYPos(ypos);
			firstMouse(false);
		}

		// calculate offset from previous frame
		float xoffset = xpos - lastXPos();
		float yoffset = lastYPos() - ypos; // reversed since y-coordinates range from bottom to top (learnopengl.com)

		lastXPos(xpos);
		lastYPos(ypos);

		xoffset *= m_sensitivity;
		yoffset *= m_sensitivity;

		m_yaw += xoffset;
		m_pitch += yoffset;

		if (m_pitch > 89.99f)
			m_pitch = 89.99f;
		if (m_pitch < -89.99f)
			m_pitch = -89.99f;

		updateCameraVectors();
	}
}


