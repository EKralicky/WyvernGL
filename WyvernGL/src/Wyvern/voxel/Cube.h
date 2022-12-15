#pragma once
#include "Wyvern.h"

class Cube {

private:
	glm::vec3 m_position;
	glm::vec4 m_color;
	const float RENDER_WIDTH = 1.0f; // This should be 1 at all times

public:
	Cube(glm::vec3 position, glm::vec4 color);
	~Cube();
	std::vector<glm::vec3> getVertexPositions();
	std::vector<glm::vec3> getVertexNormals();
	glm::vec4 getCubeColor();
	std::vector<float> generateCubeMesh();

};