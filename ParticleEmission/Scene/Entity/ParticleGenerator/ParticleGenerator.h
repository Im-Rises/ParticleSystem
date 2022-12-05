/*
#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include "../Entity.h"
#include <glad/include/glad/glad.h>
#include <glm/glm.hpp>

#define MaxParticles 10000

struct Particle {
    glm::vec3 pos, speed;
    unsigned char r, g, b, a; // Color
    float size, angle, weight;
    float life; // Remaining life of the particle. if <0 : dead and unused.
    float cameradistance; // *Squared* distance to the camera. if dead : -1.0f

    bool operator<(const Particle &that) const {
        // Sort in reverse order : far particles drawn first.
        return this->cameradistance > that.cameradistance;
    }
};

class ParticleGenerator : public Entity {
private:
    // OpenGL buffer data
    static inline constexpr GLfloat gVertexBufferData[] = {
            -0.5F,
            -0.5F,
            0.0F,
            0.5F,
            -0.5F,
            0.0F,
            -0.5F,
            0.5F,
            0.0F,
            0.5F,
            0.5F,
            0.0F,
    };
    Particle ParticlesContainer[MaxParticles];
    int LastUsedParticle = 0;

public:
    ParticleGenerator();

    void init();

    ~ParticleGenerator();

    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

    int FindUnusedParticle();

    void SortParticles();

private:
    int findUnusedParticle();
};


#endif // PARTICLEGENERATOR_H
*/
