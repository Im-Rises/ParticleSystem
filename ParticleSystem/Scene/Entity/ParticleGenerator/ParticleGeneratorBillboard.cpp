#include "ParticleGeneratorBillboard.h"

#include <iostream>
#include <algorithm>

ParticleGeneratorBillboard::ParticleGeneratorBillboard(int maxParticles) : Entity("shaders/BillboardParticle.vert",
                                                                               "shaders/BillboardParticle.frag"),
                                                                           texture("textures/ball.png"),
                                                                           randomEngine(std::random_device()()) {
    // Init particles
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    particlesCount = maxParticles;
    particles.resize(particlesCount);
    resetParticles();
    // Init opengl buffers
    create();
}

void ParticleGeneratorBillboard::create() {
    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Particle) * particles.size(), particles.data(), GL_DYNAMIC_DRAW);
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
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, position));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, scale));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, color));
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
    for (int i = 0; i < particlesCount; i++)
    {
        particles[i].lifeTime -= deltaTime;

        if (particles[i].lifeTime > 0)
        {
            particles[i].velocity += sumForces * deltaTime;
            particles[i].position += particles[i].velocity * deltaTime;
        }
        else
        {
            resetParticle(i);
        }
    }
}

void ParticleGeneratorBillboard::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {

    /* Sort particles using camera distance to blend correctly*/
    // Calculate camera distance
    glm::mat4 inv_view_matrix = glm::inverse(cameraViewMatrix);
    auto cameraPos = glm::vec3(inv_view_matrix[3]);
    for (int i = 0; i < particlesCount; i++)
    {
        particles[i].cameraDistance = glm::length_t(glm::length(cameraPos - particles[i].position));
    }
    // Sort particles
    std::sort(particles.begin(), particles.end(), [](const Particle& a, const Particle& b) {
        return a.cameraDistance > b.cameraDistance;
    });

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
    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, (GLsizei)particles.size());
    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Particle) * particles.size(), particles.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ParticleGeneratorBillboard::resetParticles() {
    for (int i = 0; i < particlesCount; i++)
    {
        resetParticle(i);
    }
}

void ParticleGeneratorBillboard::resetParticle(unsigned int index) {
    if (randomizePosition)
    {
        switch (spreadType)
        {
        case SpreadType::SPREAD_TYPE_SPHERE:
            particles[index].position = randomVec3InSphere(spreadRadius);
            break;
        case SpreadType::SPREAD_TYPE_RECTANGLE:
            particles[index].position = randomVec3InRectangle(minRectangleSpread, maxRectangleSpread);
            break;
        default:
            break;
        }
    }
    else
        particles[index].position = position;

    if (randomizeInitialVelocity)
        particles[index].velocity = randomVec3(minInitialVelocity, maxInitialVelocity);
    else
        particles[index].velocity = fixedInitialVelocity;

    if (randomizeLifeTime)
        particles[index].lifeTime = randomFloat(minLifeTime, maxLifeTime);
    else
        particles[index].lifeTime = fixedLifeTime;

    if (randomizeScale)
    {
        if (keepScaleAspectRatio)
        {
            float scale = randomFloat(minScale.x, maxScale.x);
            particles[index].scale = { scale, scale };
        }
        else
            particles[index].scale = randomVec2(minScale, maxScale);
    }
    else
        particles[index].scale = fixedScale;

    if (randomizeColor)
    {
        if (randomizeColorAlpha)
        {
            glm::vec3 randomColor = { randomFloat(minColor.x, maxColor.x), randomFloat(minColor.y, maxColor.y), randomFloat(minColor.z, maxColor.z) };
            float randomAlpha = randomFloat(minColorAlpha, maxColorAlpha);
            particles[index].color = { randomColor.x, randomColor.y, randomColor.z, randomAlpha };
        }
        else
        {
            glm::vec3 randomColor = { randomFloat(minColor.x, maxColor.x), randomFloat(minColor.y, maxColor.y), randomFloat(minColor.z, maxColor.z) };
            particles[index].color = { randomColor.x, randomColor.y, randomColor.z, fixedColorAlpha };
        }
    }
    else
    {
        if (randomizeColorAlpha)
        {
            particles[index].color = { fixedColor.x, fixedColor.y, fixedColor.z, randomFloat(minColorAlpha, maxColorAlpha) };
        }
        else
        {
            particles[index].color = { fixedColor.x, fixedColor.y, fixedColor.z, fixedColorAlpha };
        }
    }
}

float ParticleGeneratorBillboard::randomFloat(float min, float max) {
    if (min > max)
        std::swap(min, max);
    std::uniform_real_distribution<float> dist(min, max);
    return dist(randomEngine);
}

glm::vec2 ParticleGeneratorBillboard::randomVec2(glm::vec2 min, glm::vec2 max) {
    return { randomFloat(min.x, max.x), randomFloat(min.y, max.y) };
}

glm::vec3 ParticleGeneratorBillboard::randomVec3(glm::vec3 min, glm::vec3 max) {
    return { randomFloat(min.x, max.x), randomFloat(min.y, max.y), randomFloat(min.z, max.z) };
}

glm::vec4 ParticleGeneratorBillboard::randomVec4(glm::vec4 min, glm::vec4 max) {
    return { randomFloat(min.x, max.x), randomFloat(min.y, max.y), randomFloat(min.z, max.z), randomFloat(min.w, max.w) };
}

glm::vec3 ParticleGeneratorBillboard::randomVec3InSphere(float radius) {
    glm::vec3 randomVec = randomVec3({ -1, -1, -1 }, { 1, 1, 1 });
    return glm::normalize(randomVec) * randomFloat(0, radius) + position;
}

glm::vec3 ParticleGeneratorBillboard::randomVec3InRectangle(glm::vec3 min, glm::vec3 max) {
    return randomVec3(min, max) + position;
}

void ParticleGeneratorBillboard::setParticlesCount(int maxParticles) {
    particlesCount = maxParticles;
    particles.resize(particlesCount);
    particles.resize(particlesCount);
    resetParticles();
}

int ParticleGeneratorBillboard::getParticlesCount() const {
    return particlesCount;
}
