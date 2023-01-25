#include "Billboard.h"

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION

#include <stb/stb_image.h>

Billboard::Billboard()
    : Entity("shaders/Billboard.vert", "shaders/Billboard.frag"), texture("textures/ball2.png") {
    create();
    position = glm::vec3(1.0F, 0.0F, 0.0F);
    updateModelMatrix();
}

void Billboard::create() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

Billboard::~Billboard() {
    destroy();
}

void Billboard::destroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Billboard::update(float deltaTime) {
}

void Billboard::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {
    // Shader
    shader.use();
    shader.setMat4("view", cameraViewMatrix);
    shader.setMat4("projection", cameraProjectionMatrix);
    shader.setVec3("cameraRight",
        glm::vec3(cameraViewMatrix[0][0], cameraViewMatrix[1][0], cameraViewMatrix[2][0]));
    shader.setVec3("cameraUp",
        glm::vec3(cameraViewMatrix[0][1], cameraViewMatrix[1][1], cameraViewMatrix[2][1]));
    shader.setVec3("billboardPos", position);
    shader.setVec2("billboardSize", glm::vec2(scale.x, scale.y));

    // Texture
    glBindTexture(GL_TEXTURE_2D, texture.getTexture());

    // Draw
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
