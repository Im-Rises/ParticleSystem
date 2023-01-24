#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "../../Shader/Shader.h"
//#include <glm/glm.hpp>

class Entity {
protected:
    glm::vec3 position = glm::vec3(0.0F, 0.0F, 0.0F);
    glm::vec3 rotation = glm::vec3(0.0F, 0.0F, 0.0F);
    glm::vec3 scale = glm::vec3(1.0F, 1.0F, 1.0F);

    glm::mat4 modelMatrix;

    Shader shader;

//    unsigned int texture;

public:
    Entity(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);

    ~Entity();

    virtual void update(float deltaTime) = 0;

    virtual void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) = 0;

    void updateModelMatrix();

//    void loadTexture(const std::string_view &texturePath);
};


#endif //ENTITY_H
