#ifndef CUBE_H
#define CUBE_H

#include <array>

#include "../Entity.h"
#include "../../../Shader/Shader.h"

class Cube : public Entity {
private:
    unsigned int VAO, VBO;

    const std::array<float, 18> vertices = {
            // first triangle
            0.5f, 0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, 0.5f, 0.0f,  // top left
            // second triangle
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f, 0.5f, 0.0f   // top left
    };

public:
    Cube();

    void create();

    ~Cube();

    void destroy();

    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;
};


#endif //CUBE_H
