#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H

#include <vector>
#include <glad/include/glad/glad.h>
#include <glm/glm.hpp>

#include "../Entity.h"

/*
 * Two solutions:
 * 1. Create separate arrays for, position, color, etc...
 * 2. Create a single array base on a struct containing all the data
 */

class ParticleGenerator : public Entity {
private:
    float quadVertices[30] = {
            // positions     // colors
            -0.05f, 0.05f, 1.0f, 0.0f, 0.0f,
            0.05f, -0.05f, 0.0f, 1.0f, 0.0f,
            -0.05f, -0.05f, 0.0f, 0.0f, 1.0f,

            -0.05f, 0.05f, 1.0f, 0.0f, 0.0f,
            0.05f, -0.05f, 0.0f, 1.0f, 0.0f,
            0.05f, 0.05f, 0.0f, 1.0f, 1.0f
    };

    glm::vec2 translations[100];

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
