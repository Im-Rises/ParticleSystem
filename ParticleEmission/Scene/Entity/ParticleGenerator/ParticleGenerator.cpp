#include "ParticleGenerator.h"

#include <iostream>

ParticleGenerator::ParticleGenerator() : Entity(
        "shaders/ParticleGenerator.vert",
        "shaders/ParticleGenerator.frag") {
    init();
}

void ParticleGenerator::init() {
    int index = 0;
    float offset = 0.1f;
    for (int y = -10; y < 10; y += 2) {
        for (int x = -10; x < 10; x += 2) {
            glm::vec3 translation;
            translation.x = (float) x / 10.0f + offset;
            translation.y = (float) y / 10.0f + offset;
            translation.z = -2.0f;
            translations[index++] = translation;
        }
    }

    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * translations.size(), translations.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO); // this attribute comes from a different vertex buffer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glVertexAttribDivisor(1, 1); // tell OpenGL this is an instanced vertex attribute.
}

ParticleGenerator::~ParticleGenerator() {
    destroy();
}

void ParticleGenerator::destroy() {
    glDeleteVertexArrays(1, &quadVAO);
    glDeleteBuffers(1, &quadVBO);
}

void ParticleGenerator::update(float deltaTime) {

}

void ParticleGenerator::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {
    // Shader
    shader.use();
//    shader.setMat4("model", modelMatrix);
    shader.setMat4("view", cameraViewMatrix);
    shader.setMat4("projection", cameraProjectionMatrix);

    // Draw
    glBindVertexArray(quadVAO);
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, translations.size()); // 100 triangles of 6 vertices each
    glBindVertexArray(0);
}
