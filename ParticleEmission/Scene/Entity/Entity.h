#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "../../Shader/Shader.h"
#include "Components/Transform.h"

class Entity {
protected:
    Transform transform;
    Shader shader;
    unsigned int VAO, VBO;

public:
    Entity(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);

    void create();

    ~Entity();

    void destroy();

    virtual void update(float deltaTime) = 0;

    virtual void render(glm::mat4 cameraProjectionMatrix, glm::mat4 cameraViewMatrix) = 0;
};


#endif //ENTITY_H
