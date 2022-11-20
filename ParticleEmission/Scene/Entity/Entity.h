#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "../../Shader/Shader.h"


class Entity {
protected:
    Shader shader;
    unsigned int VAO, VBO;

public:
    Entity(std::string vertexShaderPath, std::string fragmentShaderPath);

    void create();

    ~Entity();

    void destroy();

    void virtual update(float deltaTime) = 0;

    void virtual render() = 0;
};


#endif //ENTITY_H
