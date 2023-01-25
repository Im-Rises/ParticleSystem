#include "ParticleGeneratorBillboard.h"

ParticleGeneratorBillboard::ParticleGeneratorBillboard() : Entity(
        "shaders/BillboardParticle.vert",
        "shaders/BillboardParticle.frag") {
    init();
}

void ParticleGeneratorBillboard::init() {
    int index = 0;
    float offset = 0.1f;
    for (int y = -10; y < 10; y += 2) {
        for (int x = -10; x < 10; x += 2) {
            glm::vec3 translation;
            translation.x = (float) x / 10.0f + offset;
            translation.y = (float) y / 10.0f + offset;
            translation.z = 0.0f;
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

ParticleGeneratorBillboard::~ParticleGeneratorBillboard() {
    destroy();
}

void ParticleGeneratorBillboard::destroy() {
    glDeleteVertexArrays(1, &quadVAO);
    glDeleteBuffers(1, &quadVBO);
}

void ParticleGeneratorBillboard::update(float deltaTime) {

}

void ParticleGeneratorBillboard::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {
    // Shader
    shader.use();
    shader.setMat4("view", cameraViewMatrix);
    shader.setMat4("projection", cameraProjectionMatrix);
    shader.setVec3("cameraRight", cameraViewMatrix[0][0], cameraViewMatrix[1][0], cameraViewMatrix[2][0]);
    shader.setVec3("cameraUp", cameraViewMatrix[0][1], cameraViewMatrix[1][1], cameraViewMatrix[2][1]);

    // Draw
    glBindVertexArray(quadVAO);
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, translations.size());
    glBindVertexArray(0);
}
