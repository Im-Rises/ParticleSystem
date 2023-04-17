#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H

#include <vector>
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
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
    };

    struct Particle {
        glm::vec3 position;
        glm::vec2 scale;
        glm::vec4 color;
        glm::vec3 velocity;
        float lifeTime;
        glm::length_t cameraDistance;
        Particle() : position(0.0f), scale(0.1f), color(1.0f), velocity(0.0f), lifeTime(0.0f), cameraDistance(glm::length_t(0.0f)) {}
    };

    std::vector<Particle> particles;

    unsigned int instanceVBO;
    unsigned int quadVAO, quadVBO;

    Texture texture;

public:
    glm::vec3 sumForces = glm::vec3(0.0f, -9.81, 0.0f);

    SpreadType spreadType = SPREAD_TYPE_SPHERE;
    float spreadRadius = 2.0f;
    bool randomizePosition = true;
    glm::vec3 minRectangleSpread = glm::vec3(-3.0f, -2.0f, -1.0f);
    glm::vec3 maxRectangleSpread = glm::vec3(+3.0f, +2.0f, +1.0f);

    bool randomizeInitialVelocity = true;
    glm::vec3 fixedInitialVelocity = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 minInitialVelocity = glm::vec3(-1.0f, +1.0f, -1.0f);
    glm::vec3 maxInitialVelocity = glm::vec3(+1.0f, +5.0f, +1.0f);

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
    bool randomizeColorAlpha = true;
    glm::vec3 fixedColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 minColor = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 maxColor = glm::vec3(1.0f, 1.0f, 1.0f);
    float fixedColorAlpha = 1.0f;
    float minColorAlpha = 0.0f;
    float maxColorAlpha = 1.0f;

public:
#ifdef __EMSCRIPTEN__
    explicit ParticleGeneratorBillboard(int particlesCount = 10000);
#else
    explicit ParticleGeneratorBillboard(int particlesCount = 25000);
#endif

    void create();
    ~ParticleGeneratorBillboard();
    void destroy();

public:
    void update(float deltaTime) override;
    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

public:
    void resetParticles();

private:
    void resetParticle(unsigned int index);

private:
    float randomFloat(float min, float max);
    glm::vec2 randomVec2(glm::vec2 min, glm::vec2 max);
    glm::vec3 randomVec3(glm::vec3 min, glm::vec3 max);
    glm::vec4 randomVec4(glm::vec4 min, glm::vec4 max);
    glm::vec3 randomVec3InSphere(float radius);
    glm::vec3 randomVec3InRectangle(glm::vec3 min, glm::vec3 max);

public:
    void setParticlesCount(int maxParticles);
    [[nodiscard]] int getParticlesCount() const;
};

#endif // PARTICLE_GENERATOR_H
