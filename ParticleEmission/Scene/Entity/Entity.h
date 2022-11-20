#ifndef ENTITY_H
#define ENTITY_H

#include "../../Shader/Shader.h"


class Entity {
private:
    Shader shader;

public:
    Entity();

    ~Entity();

    void virtual update(float deltaTime) = 0;

    void virtual render() = 0;
};


#endif //ENTITY_H
