#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    // Define the camera Up
    const glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    // Matrix transformations
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;


    glm::vec3 cameraFrontBuffer = glm::vec3(0.0f, 0.0f, -1.0f);


public:
    // Camera attributes
    float movementSpeed = 1.0F;
    float rotationSpeed = 1.0F;
    float fov = 90.0F;
    float nearPlane = 0.1F;
    float farPlane = 100.0F;

    // Position and rotation of the camera
    bool constrainPitch = true;
    float yaw = -90.0f;
    float pitch = 0.0f;
    glm::vec3 position;

    // Movement buffer to take into account the deltaTime
    glm::vec3 movementBuffer;

public:
    Camera(int display_w, int display_h);

    ~Camera();

public:
    void update(float deltaTime);

private:
    void updateViewMatrix();

public:
    void updateProjectionMatrix(int display_w, int display_h);

public:
//    void setMovementBuffer(glm::vec3 movement);
    void moveForward();

    void moveBackward();

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();


public:
    [[nodiscard]] glm::mat4 getViewMatrix() const;

    [[nodiscard]] glm::mat4 getProjectionMatrix() const;

};


#endif //CAMERA_H
