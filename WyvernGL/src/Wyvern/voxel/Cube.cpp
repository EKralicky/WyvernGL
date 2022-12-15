#include "Cube.h"
#include "Face.h"

Cube::Cube(glm::vec3 position, glm::vec4 color)
    : m_position(position), m_color(color)
{
    
}

Cube::~Cube()
{
}


glm::vec4 Cube::getCubeColor() {
    return m_color;
}

// So we acutally need 24 vertices here instead of 8 if we want to factor in surface normals. 
// 4 verts per side. Each corner vertex having its own normal


/*
Front Face: N(0, 0, 1) +Z
    Tri 1 (top let)
    (1, 1, 1) 1
    (1, -1, 1) 
    (-1, 1, 1) 
    Tri 2 (bottom right)
    (-1, 1, 1) 
    (1, -1, 1) 
    (-1, -1, 1) 
    Unique Vertices
    (1, 1, 1) 0
    (1, -1, 1) 1
    (-1, 1, 1) 2
    (-1, -1, 1) 3
    Indices
    0, 1, 2
    2, 1, 3

Back Face: N(0, 0, -1) -Z
    (-1, 1, -1) 4
    (-1, -1, -1) 5
    (1, 1, -1) 6
    (1, -1, -1) 7
    Indices
    4, 5, 6
    6, 5, 7

Top Face: N(0, 1, 0) +Y
    (-1, 1, 1) 8
    (-1, 1, -1) 9
    (1, 1, 1) 10
    (1, 1, -1) 11
    Indices
    8, 9, 10
    10, 9, 11

Bottom Face: N(0, -1, 0) -Y
    (-1, -1, -1) 12
    (-1, -1, 1) 13
    (1, -1, -1) 14
    (1, -1, 1) 15
    Indices
    12, 13, 14
    14, 13, 15
Left Face: N(-1, 0, 0) -X
    (-1, 1, 1) 16
    (-1, -1, 1) 17
    (-1, 1, -1) 18
    (-1, -1, -1) 19
    Indices
    16, 17, 18
    18, 17, 19

Right Face: N(1, 0, 0) +X
    (1, 1, -1) 20
    (1, -1, -1) 21
    (1, 1, 1) 22
    (1, -1, 1) 23
    Indices
    20, 21, 22
    22, 21, 23




*/





std::vector<glm::vec3> Cube::getVertexPositions()
{
    std::vector<glm::vec3> cubeVertices;
    // Front
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    // Back
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    // Top
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    // Bottom
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    // Right
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x + RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    // Left
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z + RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y + RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));
    cubeVertices.push_back(glm::vec3(m_position.x - RENDER_WIDTH / 2.000, m_position.y - RENDER_WIDTH / 2.000, m_position.z - RENDER_WIDTH / 2.000));

    
    return cubeVertices;
}

std::vector<glm::vec3> Cube::getVertexNormals()
{
    std::vector<glm::vec3> cubeNormals;
    //front
    for (int i = 0; i < 4; ++i) {
        cubeNormals.push_back(glm::vec3(0, 0, 1));
    }
    //back
    for (int i = 0; i < 4; ++i) {
        cubeNormals.push_back(glm::vec3(0, 0, -1));
    }
    //top
    for (int i = 0; i < 4; ++i) {
        cubeNormals.push_back(glm::vec3(0, 1, 0));
    }
    //bottom
    for (int i = 0; i < 4; ++i) {
        cubeNormals.push_back(glm::vec3(0, -1, 0));
    }
    //left
    for (int i = 0; i < 4; ++i) {
        cubeNormals.push_back(glm::vec3(1, 0, 0));
    }
    for (int i = 0; i < 4; ++i) {
        cubeNormals.push_back(glm::vec3(-1, 0, 0));
    }
    return cubeNormals;
}

std::vector<float> Cube::generateCubeMesh()
{
    std::vector<float> verticesWithAttributes;
    std::vector<glm::vec3> vertexPositions = Cube::getVertexPositions();
    std::vector<glm::vec3> vertexNormals = Cube::getVertexNormals();
    glm::vec4 cubeColor = getCubeColor();
    for (int i = 0; i < vertexPositions.size(); ++i) {
        verticesWithAttributes.push_back(vertexPositions[i].x);
        verticesWithAttributes.push_back(vertexPositions[i].y);
        verticesWithAttributes.push_back(vertexPositions[i].z);
        verticesWithAttributes.push_back(vertexNormals[i].x);
        verticesWithAttributes.push_back(vertexNormals[i].y);
        verticesWithAttributes.push_back(vertexNormals[i].z);
        verticesWithAttributes.push_back(cubeColor.r);
        verticesWithAttributes.push_back(cubeColor.g);
        verticesWithAttributes.push_back(cubeColor.b);
        verticesWithAttributes.push_back(cubeColor.a);
    }
    return verticesWithAttributes;
}
