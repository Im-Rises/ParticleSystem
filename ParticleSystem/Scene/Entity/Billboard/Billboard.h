#ifndef BILLBOARD_H
#define BILLBOARD_H

#include <array>
#include "../Entity.h"

class Billboard : public Entity {
private:
    unsigned int VAO, VBO;

    static constexpr std::array<float, 18> vertices = {
            -0.5f, -0.5f, -0.0f,
            0.5f, -0.5f, -0.0f,
            0.5f, 0.5f, -0.0f,

            0.5f, 0.5f, -0.f,
            -0.5f, 0.5f, -0.0f,
            -0.5f, -0.5f, -0.0f,
    };

    unsigned int texture;


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

private:
    void loadTexture(const std::string_view &texturePath);
};


#endif //BILLBOARD_H
