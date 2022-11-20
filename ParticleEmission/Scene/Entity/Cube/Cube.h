#ifndef CUBE_H
#define CUBE_H

#include <array>

#include "../Entity.h"
#include "../../../Shader/Shader.h"

class Cube : public Entity {
private:
    const std::array<float, 12> vertices = {
            -0.5F, -0.5F, 0.0F,
            0.5F, -0.5F, 0.0F,
            -0.5F, 0.5F, 0.0F,
            0.5F, 0.5F, 0.0F,
    };

public:
    Cube();

//    ~Cube();

    void update(float deltaTime) override;

    void render(glm::mat4 cameraProjectionMatrix, glm::mat4 cameraViewMatrix) override;

    void updateModelMatrix();
};


#endif //CUBE_H
