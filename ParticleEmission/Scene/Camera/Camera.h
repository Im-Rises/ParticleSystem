#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    glm::vec3 movementBuffer;

public:
    float movementSpeed = 1.0F;
    float rotationSpeed = 1.0F;

    float fov = 90.0F;
    float nearPlane = 0.1F;
    float farPlane = 100.0F;

    bool constrainPitch = true;
    float yaw = -90.0f;
    float pitch = 0.0f;

    glm::vec3 position;
//    glm::vec3 rotation;

public:
    Camera(int display_w, int display_h);

    ~Camera();

private:
    void updateViewMatrix();

public:
    void updateProjectionMatrix(int display_w, int display_h);

public:
    void update(float deltaTime);

//public:
//    void moveForward() {
//        movementBuffer.z = -1.0F;
//    }
//
//    void moveBackward() {
//        movementBuffer.z = +1.0F;
//    }
//
//    void moveLeft() {
//        movementBuffer.x = -1.0F;
//    }
//
//    void moveRight() {
//        movementBuffer.x = +1.0F;
//    }
//
//    void moveUp() {
//        movementBuffer.y = +1.0F;
//    }
//
//    void moveDown() {
//        movementBuffer.y = -1.0F;
//    }

public:
    [[nodiscard]] glm::mat4 getViewMatrix() const;

    [[nodiscard]] glm::mat4 getProjectionMatrix() const;

};


#endif //CAMERA_H
