#include "ParticleGenerator.h"


ParticleGenerator::ParticleGenerator() {
    glGenBuffers(1, &billboardVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, billboardVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData), gVertexBufferData, GL_STATIC_DRAW);

    glGenBuffers(1, &particlesPositionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, particlesPositionBuffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLfloat), nullptr, GL_STREAM_DRAW);

    GLuint particles_color_buffer;
    glGenBuffers(1, &particles_color_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLubyte), nullptr, GL_STREAM_DRAW);
}

ParticleGenerator::~ParticleGenerator() {
    glDeleteBuffers(1, &particlesColorBuffer);
    glDeleteBuffers(1, &particlesPositionBuffer);
    glDeleteBuffers(1, &billboardVertexBuffer);
}

void ParticleGenerator::update(float deltaTime) {
    int newparticles = (int) (deltaTime * 10000.0);
    if (newparticles > (int) (0.016f * 10000.0))
        newparticles = (int) (0.016f * 10000.0);

    for (int i = 0; i < newparticles; i++) {
        int particleIndex = findUnusedParticle();
        particlesContainer[particleIndex].life = 5.0f;
        particlesContainer[particleIndex].pos = glm::vec3(0, 0, 0);

        float spread = 1.5f;
        glm::vec3 maindir = glm::vec3(0.0f, 10.0f, 0.0f);
        // Very bad way to generate a random direction;
        // See for instance http://stackoverflow.com/questions/5408276/python-uniform-spherical-distribution instead,
        // combined with some user-controlled parameters (main direction, spread, etc)
        glm::vec3 randomdir = glm::vec3(
                (rand() % 2000 - 1000.0f) / 1000.0f,
                (rand() % 2000 - 1000.0f) / 1000.0f,
                (rand() % 2000 - 1000.0f) / 1000.0f
        );

        particlesContainer[particleIndex].speed = maindir + randomdir * spread;

        // Very bad way to generate a random color
        particlesContainer[particleIndex].r = 255;
        particlesContainer[particleIndex].g = 255;
        particlesContainer[particleIndex].b = 255;
        particlesContainer[particleIndex].a = (rand() % 256) / 3;

        particlesContainer[particleIndex].size = (rand() % 1000) / 2000.0f + 0.1f;
    }

    // Simulate all particles
    int ParticlesCount = 0;
    for (int i = 0; i < MAX_PARTICLES; i++) {

        Particle &p = particlesContainer[i]; // shortcut

        if (p.life > 0.0f) {

            // Decrease life
            p.life -= deltaTime;
            if (p.life > 0.0f) {

                // Simulate simple physics : gravity only, no collisions
                p.speed += glm::vec3(0.0f, -9.81f, 0.0f) * (float) deltaTime * 0.5f;
                p.pos += p.speed * (float) deltaTime;
//                p.cameraDistance = glm::length2(p.pos - glm::vec3(0, 0, 0));
                p.cameraDistance = glm::length(p.pos - glm::vec3(0, 0, 0));

                // Fill the GPU buffer
                gParticlePositionData[4 * ParticlesCount + 0] = p.pos.x;
                gParticlePositionData[4 * ParticlesCount + 1] = p.pos.y;
                gParticlePositionData[4 * ParticlesCount + 2] = p.pos.z;

                gParticlePositionData[4 * ParticlesCount + 3] = p.size;

                gParticleColorData[4 * ParticlesCount + 0] = p.r;
                gParticleColorData[4 * ParticlesCount + 1] = p.g;
                gParticleColorData[4 * ParticlesCount + 2] = p.b;
                gParticleColorData[4 * ParticlesCount + 3] = p.a;

            } else {
                // Particles that just died will be put at the end of the buffer in SortParticles();
                p.cameraDistance = -1.0f;
            }

            ParticlesCount++;

        }
    }
}

void ParticleGenerator::render() {
    glBindBuffer(GL_ARRAY_BUFFER, particlesPositionBuffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLfloat), nullptr, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, particlesCount * sizeof(GLfloat) * 4, gParticlePositionData);

    glBindBuffer(GL_ARRAY_BUFFER, particlesColorBuffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLubyte), nullptr,
                 GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, particlesCount * sizeof(GLubyte) * 4, gParticleColorData);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, billboardVertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, particlesPositionBuffer);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void *) 0);

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, particlesColorBuffer);
    glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, (void *) 0);

    glVertexAttribDivisor(0, 0);
    glVertexAttribDivisor(1, 1);
    glVertexAttribDivisor(2, 1);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, particlesCount);
}

int ParticleGenerator::findUnusedParticle() {
    for (int i = lastUsedParticle; i < MAX_PARTICLES; i++) {
        if (particlesContainer[i].life < 0) {
            lastUsedParticle = i;
            return i;
        }
    }

    for (int i = 0; i < lastUsedParticle; i++) {
        if (particlesContainer[i].life < 0) {
            lastUsedParticle = i;
            return i;
        }
    }

    return 0;
}
