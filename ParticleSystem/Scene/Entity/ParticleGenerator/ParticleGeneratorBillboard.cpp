#include "ParticleGeneratorBillboard.h"

ParticleGeneratorBillboard::ParticleGeneratorBillboard() : Entity("shaders/BillboardParticle.vert",
                                                               "shaders/BillboardParticle.frag"),
                                                           texture("textures/ball2.png") {
    create();
    position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void ParticleGeneratorBillboard::create() {
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        resetParticle(i);
    }

    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Particle) * particles.size(), particles.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    glBindVertexArray(quadVAO);
    glGenBuffers(1, &quadEBO);

    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO); // this attribute comes from a different vertex buffer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(3);

    glVertexAttribDivisor(1, 1); // tell OpenGL this is an instanced vertex attribute.
    glVertexAttribDivisor(2, 1);
    glVertexAttribDivisor(3, 1);

    glBindVertexArray(0);
}

ParticleGeneratorBillboard::~ParticleGeneratorBillboard() {
    destroy();
}

void ParticleGeneratorBillboard::destroy() {
    glDeleteVertexArrays(1, &quadVAO);
    glDeleteBuffers(1, &quadVBO);
    glDeleteBuffers(1, &quadEBO);
}

void ParticleGeneratorBillboard::update(float deltaTime) {
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        movementData[i].lifeTime -= deltaTime;

        if (movementData[i].lifeTime > 0)
        {
            movementData[i].velocity += sumForces * deltaTime;
            particles[i].position += movementData[i].velocity * deltaTime;
        }
        else
        {
            resetParticle(i);
        }
    }
}

void ParticleGeneratorBillboard::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {
    // Shader
    shader.use();
    shader.setMat4("u_view", cameraViewMatrix);
    shader.setMat4("u_projection", cameraProjectionMatrix);
    shader.setVec3("u_cameraRight", cameraViewMatrix[0][0], cameraViewMatrix[1][0], cameraViewMatrix[2][0]);
    shader.setVec3("u_cameraUp", cameraViewMatrix[0][1], cameraViewMatrix[1][1], cameraViewMatrix[2][1]);

    // Texture
    glBindTexture(GL_TEXTURE_2D, texture.getTexture());

    // Draw
    glBindVertexArray(quadVAO);
    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, particles.size());
    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Particle) * particles.size(), particles.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ParticleGeneratorBillboard::resetParticle(unsigned int index) {
    movementData[index].lifeTime = randomValue(minLifeTime, maxLifeTime);
    movementData[index].velocity = randomVec3(minInitialVelocity, maxInitialVelocity);

    particles[index].position = randomVec3(minSpread, maxSpread) + position;
    particles[index].scale = randomVec2(minScale, maxScale);
    particles[index].color = randomVec3(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
}
