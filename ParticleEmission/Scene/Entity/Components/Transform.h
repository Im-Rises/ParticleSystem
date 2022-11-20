#ifndef TRANSFORM_H
#define TRANSFORM_H


#include "glm/vec3.hpp"

class Transform {
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

//public:
//    Transform();
//
//    Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
//
//    ~Transform();
//
//    void setPosition(glm::vec3 position);
//
//    void setRotation(glm::vec3 rotation);
//
//    void setScale(glm::vec3 scale);
//
//    glm::vec3 getPosition();
//
//    glm::vec3 getRotation();
//
//    glm::vec3 getScale();
//
//    glm::mat4 getModelMatrix();
};


#endif //TRANSFORM_H
