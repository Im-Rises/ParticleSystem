#ifndef BILLBOARD_H
#define BILLBOARD_H

#include <array>
#include "../Entity.h"
#include "../../../Texture/Texture.h"

class Billboard : public Entity {
private:
    unsigned int VAO, VBO, EBO;

    static constexpr std::array<float, 20> vertices = {
            // positions          // texture coords
            0.5f, 0.5f, 0.0f, 1.0f, 1.0f, // top right
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f  // top left
    };

    static constexpr std::array<unsigned int, 6> indices = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };

    Texture texture;


public:
    Billboard();

private:
    void create();

public:
    ~Billboard();

private:
    void destroy();

public:
    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

};


#endif //BILLBOARD_H
