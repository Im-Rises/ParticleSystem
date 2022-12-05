#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "../../Shader/Shader.h"
#include "Components/Transform.h"

class Entity {
protected:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::mat4 modelMatrix;

    Shader shader;

public:
    Entity(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);

    ~Entity();

    virtual void update(float deltaTime) = 0;

    virtual void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) = 0;

    void updateModelMatrix();
};


#endif //ENTITY_H
