#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include "../Entity.h"
#include <glad/include/glad/glad.h>
#include <glm/glm.hpp>

#define MAX_PARTICLES 10000

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
    GLfloat gParticlePositionData[MAX_PARTICLES * 4];
    GLfloat gParticleColorData[MAX_PARTICLES * 4];

    // OpenGL buffer
    GLuint billboardVertexBuffer;
    GLuint particlesPositionBuffer;
    GLuint particlesColorBuffer;

    // Particles
    GLuint particlesCount = 0;

    struct Particle {
        glm::vec3 pos, speed;
        unsigned char r, g, b, a;
        float size, angle, weight;
        float life;
        float cameraDistance;
    };

    Particle particlesContainer[MAX_PARTICLES];

    int lastUsedParticle = 0;

public:
    ParticleGenerator();

    void init();

    ~ParticleGenerator();

    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

private:
    int findUnusedParticle();
};


#endif // PARTICLEGENERATOR_H
