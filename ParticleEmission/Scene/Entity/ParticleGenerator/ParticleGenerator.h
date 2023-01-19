#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H

#include <vector>
#include <glad/include/glad/glad.h>
#include <glm/glm.hpp>
#include <array>

#include "../Entity.h"

class ParticleGenerator : public Entity {
private:
    static constexpr const float quadVertices[18] = {
            -0.05f, 0.05f, 0.0f,
            0.05f, -0.05f, 0.0f,
            -0.05f, -0.05f, 0.0f,

            -0.05f, 0.05f, 0.0f,
            0.05f, -0.05f, 0.0f,
            0.05f, 0.05f, 0.0f,
    };

    std::array<glm::vec3, 100> translations;

    unsigned int instanceVBO;
    unsigned int quadVAO, quadVBO;

public:
    ParticleGenerator();

    void init();

    ~ParticleGenerator();

    void destroy();

    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

//private:
//    unsigned int FirstUnusedParticle();
//
//    void RespawnParticle(Particle &particle, Entity &object, glm::vec2 offset);
};

#endif // PARTICLE_GENERATOR_H
