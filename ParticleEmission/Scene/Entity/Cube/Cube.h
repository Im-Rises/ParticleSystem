#ifndef CUBE_H
#define CUBE_H

#include "../Entity.h"
#include "../../Shader/Shader.h"

class Cube : public Entity {
private:
    Shader shader;
//    unsigned int VAO, VBO, EBO;
//    unsigned int texture;

public:
    Cube();

    ~Cube();

    void update(float deltaTime) override;

    void render() override;
};


#endif //CUBE_H
