#pragma once
#include "Cube.h"
#include "Wyvern.h"

struct Facing {
	static constexpr glm::vec3 FACING_FRONT[4] = {
		glm::vec3(1.0, 1.0, 1.0),
		glm::vec3(1.0, -1.0, 1.0),
		glm::vec3(-1.0, 1.0, 1.0),
		glm::vec3(-1.0, -1.0, 1.0)
	};

	static constexpr glm::vec3 FACING_BACK[4] = {
		glm::vec3(1.0, 1.0, 1.0),
		glm::vec3(1.0, -1.0, 1.0),
		glm::vec3(-1.0, 1.0, 1.0),
		glm::vec3(-1.0, -1.0, 1.0)
	};

	static constexpr glm::vec3 FACING_UP[4] = {
		glm::vec3(1.0, 1.0, 1.0),
		glm::vec3(1.0, -1.0, 1.0),
		glm::vec3(-1.0, 1.0, 1.0),
		glm::vec3(-1.0, -1.0, 1.0)
	};
};

class Face {

private:
		
	glm::vec4 m_Color;
	std::vector<glm::vec3> m_VertexPositions;


public:
	Face(glm::vec4 color, glm::vec3 facing);
	void genIndices();
	inline std::vector<glm::vec3> getVertexPositions();
};

