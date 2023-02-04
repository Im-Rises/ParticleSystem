#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H

#include <vector>
#include <glad/include/glad/glad.h>
#include <glm/glm.hpp>
#include <array>

#include "../Entity.h"
#include "../../../Texture/Texture.h"

class ParticleGeneratorBillboard : public Entity {
private:
    static constexpr int MAX_PARTICLES = 10000;

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

    std::array<Particle, MAX_PARTICLES> particles;

    struct MovementData {
        glm::vec3 velocity;
        float lifeTime;
        MovementData() : velocity(0.0f), lifeTime(0.0f) {}
    };

    std::array<MovementData, MAX_PARTICLES> movementData;

    unsigned int instanceVBO;
    unsigned int quadVAO, quadVBO, quadEBO;

    Texture texture;

public:
    bool randomizeLifeTime = true;
    float minLifeTime = 0.1f;
    float maxLifeTime = 5.0f;
    glm::vec3 sumForces = glm::vec3(0.0f, -9.81, 0.0f);
    glm::vec3 minInitialVelocity = glm::vec3(-1.0f, +1.0f, -1.0f);
    glm::vec3 maxInitialVelocity = glm::vec3(+1.0f, +5.0f, +1.0f);
    glm::vec3 minSpread = glm::vec3(-3.0f, -1.0f, -1.0f);
    glm::vec3 maxSpread = glm::vec3(+3.0f, +1.0f, +1.0f);
    glm::vec2 minScale = glm::vec2(0.1f, 0.1f);
    glm::vec2 maxScale = glm::vec2(0.1f, 0.1f);

public:
    ParticleGeneratorBillboard();

    void create();

    ~ParticleGeneratorBillboard();

    void destroy();

public:
    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

private:
    void resetParticle(unsigned int index);

private:
    template <typename T>
    T randomValue(T min, T max) {
        return min + (max - min) * ((float)rand() / RAND_MAX);
    }

    glm::vec3 randomVec3(glm::vec3 min, glm::vec3 max) {
        return glm::vec3(randomValue(min.x, max.x), randomValue(min.y, max.y), randomValue(min.z, max.z));
    }

    glm::vec2 randomVec2(glm::vec2 min, glm::vec2 max) {
        return glm::vec2(randomValue(min.x, max.x), randomValue(min.y, max.y));
    }
};

#endif // PARTICLE_GENERATOR_H
