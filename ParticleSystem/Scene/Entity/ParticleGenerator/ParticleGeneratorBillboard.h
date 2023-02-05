#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H

#include <vector>
#include <glad/include/glad/glad.h>
#include <glm/glm.hpp>
#include <array>
#include <vector>
#include <random>

#include "../Entity.h"
#include "../../../Texture/Texture.h"

enum SpreadType {
    SPREAD_TYPE_SPHERE,
    SPREAD_TYPE_RECTANGLE,
};

class ParticleGeneratorBillboard : public Entity {
private:
    int particlesCount;

    std::mt19937 randomEngine;

    static constexpr std::array<float, 12> vertices = {
        // positions
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f,  // top left
    };

    static constexpr std::array<unsigned int, 6> indices = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    struct Particle {
        glm::vec3 position;
        glm::vec2 scale;
        glm::vec3 color;
        Particle() : position(0.0f), scale(0.1f), color(1.0f) {}
    };

    std::vector<Particle> particles;

    struct MovementData {
        glm::vec3 velocity;
        float lifeTime;
        MovementData() : velocity(0.0f), lifeTime(0.0f) {}
    };

    std::vector<MovementData> movementData;

    unsigned int instanceVBO;
    unsigned int quadVAO, quadVBO, quadEBO;

    Texture texture;

public:
    glm::vec3 sumForces = glm::vec3(0.0f, -9.81, 0.0f);

    bool randomizeInitialVelocity = true;
    glm::vec3 fixedInitialVelocity = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 minInitialVelocity = glm::vec3(-1.0f, +1.0f, -1.0f);
    glm::vec3 maxInitialVelocity = glm::vec3(+1.0f, +5.0f, +1.0f);

    SpreadType spreadType = SPREAD_TYPE_SPHERE;
    float spreadRadius = 2.0f;
    bool randomizePosition = true;
    glm::vec3 minRectangleSpread = glm::vec3(-3.0f, -2.0f, -1.0f);
    glm::vec3 maxRectangleSpread = glm::vec3(+3.0f, +2.0f, +1.0f);

    bool randomizeLifeTime = true;
    float fixedLifeTime = 1.0f;
    float minLifeTime = 0.1f;
    float maxLifeTime = 5.0f;

    bool randomizeScale = true;
    bool keepScaleAspectRatio = true;
    glm::vec2 fixedScale = glm::vec2(0.1f, 0.1f);
    glm::vec2 minScale = glm::vec2(0.1f, 0.1f);
    glm::vec2 maxScale = glm::vec2(0.2f, 0.2f);

    bool randomizeColor = true;
    glm::vec3 fixedColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 minColor = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 maxColor = glm::vec3(1.0f, 1.0f, 1.0f);

public:
    explicit ParticleGeneratorBillboard(int maxParticles = 10000);

    void create();

    ~ParticleGeneratorBillboard();

    void destroy();

public:
    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

public:
    void reset();

private:
    void resetParticle(unsigned int index);

private:
    float randomFloat(float min, float max);
    glm::vec2 randomVec2(glm::vec2 min, glm::vec2 max);
    glm::vec3 randomVec3(glm::vec3 min, glm::vec3 max);
    glm::vec3 randomVec3InSphere(float radius);
    glm::vec3 randomVec3InRectangle(glm::vec3 min, glm::vec3 max);

public:
    void setParticlesCount(int particlesCount);
    [[nodiscard]] const int getParticlesCount() const;
};

#endif // PARTICLE_GENERATOR_H
