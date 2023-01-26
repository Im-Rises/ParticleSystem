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
    static constexpr int MAX_PARTICLES = 1000;

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
    std::array<glm::vec3, MAX_PARTICLES> velocities;

    unsigned int instanceVBO;
    unsigned int quadVAO, quadVBO, quadEBO;

    Texture texture;

public:
    ParticleGeneratorBillboard();

    void create();

    ~ParticleGeneratorBillboard();

    void destroy();

    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;
};

#endif // PARTICLE_GENERATOR_H
