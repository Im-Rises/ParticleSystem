#include "Entity.h"

#include <glad/include/glad/glad.h>

Entity::Entity(const std::string &vertexShaderPath, const std::string &fragmentShaderPath) : shader(
        vertexShaderPath.c_str(),
        fragmentShaderPath.c_str()) {
    create();
}

void Entity::create() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    shader.use();
}

Entity::~Entity() {
    destroy();
}

void Entity::destroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
