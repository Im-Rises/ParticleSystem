#ifndef CUBE_H
#define CUBE_H

#include <array>

#include "../Entity.h"
#include "../../../Shader/Shader.h"

class Cube : public Entity {
private:
    unsigned int VAO, VBO;

    const std::array<float, 12> vertices = {
            -0.5F, -0.5F, 0.0F,
            0.5F, -0.5F, 0.0F,
            -0.5F, 0.5F, 0.0F,
            0.5F, 0.5F, 0.0F,
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
