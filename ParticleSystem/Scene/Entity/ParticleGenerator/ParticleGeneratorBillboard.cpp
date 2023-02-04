#include "ParticleGeneratorBillboard.h"

ParticleGeneratorBillboard::ParticleGeneratorBillboard(int maxParticles) : Entity("shaders/BillboardParticle.vert",
                                                                               "shaders/BillboardParticle.frag"),
                                                                           texture("textures/ball.png"),
                                                                           randomEngine(std::random_device()()) {
    // Init particles
    particlesCount = maxParticles;
    particles.resize(particlesCount);
    movementData.resize(particlesCount);
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    reset();
    // Init opengl buffers
    create();
}

void ParticleGeneratorBillboard::create() {
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
    for (int i = 0; i < particlesCount; i++)
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
    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, (GLsizei)particles.size());
    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Particle) * particles.size(), particles.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ParticleGeneratorBillboard::reset() {
    for (int i = 0; i < particlesCount; i++)
    {
        resetParticle(i);
    }
}

void ParticleGeneratorBillboard::resetParticle(unsigned int index) {
    if (randomizeInitialVelocity)
        movementData[index].velocity = randomVec3(minInitialVelocity, maxInitialVelocity);
    else
        movementData[index].velocity = fixedInitialVelocity;

    if (randomizePosition)
        particles[index].position = randomVec3(minSpread, maxSpread) + position;
    else
        particles[index].position = position;

    if (randomizeLifeTime)
        movementData[index].lifeTime = randomFloat(minLifeTime, maxLifeTime);
    else
        movementData[index].lifeTime = fixedLifeTime;

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
        particles[index].color = randomVec3(minColor, maxColor);
    else
        particles[index].color = fixedColor;
}

float ParticleGeneratorBillboard::randomFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(randomEngine);
}

glm::vec2 ParticleGeneratorBillboard::randomVec2(glm::vec2 min, glm::vec2 max) {
    return { randomFloat(min.x, max.x), randomFloat(min.y, max.y) };
}

glm::vec3 ParticleGeneratorBillboard::randomVec3(glm::vec3 min, glm::vec3 max) {
    return { randomFloat(min.x, max.x), randomFloat(min.y, max.y), randomFloat(min.z, max.z) };
}
void ParticleGeneratorBillboard::setParticlesCount(int particlesCount) {
    this->particlesCount = particlesCount;
    particles.resize(particlesCount);
    movementData.resize(particlesCount);
    reset();
}

const int ParticleGeneratorBillboard::getParticlesCount() const {
    return particlesCount;
}
