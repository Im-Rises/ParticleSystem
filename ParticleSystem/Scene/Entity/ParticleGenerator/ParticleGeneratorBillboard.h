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
    static constexpr std::array<float, 20> vertices = {
        // positions          // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f   // top left
    };

    static constexpr std::array<unsigned int, 6> indices = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

//    struct Particle {
//        glm::vec3 position, velocity;
//        glm::vec4 color;
//        float life;
//
//        Particle() : position(0.0f), velocity(0.0f), color(1.0f), life(0.0f) {}
//    };

    std::array<glm::vec3, 100> translations;

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
