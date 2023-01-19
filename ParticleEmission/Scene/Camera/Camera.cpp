#include "Camera.h"

Camera::Camera(int display_w, int display_h) {
    position = glm::vec3(0.0F, 0.0F, 3.0F);
//    rotation = glm::vec3(0.0F, 0.0F, 0.0F);
    updateViewMatrix();
    updateProjectionMatrix(display_w, display_h);
}

Camera::~Camera() {

}

void Camera::update(float deltaTime) {
    position += movementBuffer * movementSpeed * deltaTime;

    updateViewMatrix();

    movementBuffer = glm::vec3(0.0F);
}

void Camera::updateViewMatrix() {
    viewMatrix = glm::lookAt(position, position + cameraFrontBuffer, cameraUp);
}

void Camera::updateProjectionMatrix(int display_w, int display_h) {
    /*
     * Update the projection matrix when the window is resized
     */
    projectionMatrix = glm::perspective(glm::radians(fov / 2), (float) display_w / (float) display_h, nearPlane,
                                        farPlane);
}

void Camera::moveForward() {
    movementBuffer.z -= 1.0F;
}

void Camera::moveBackward() {
    movementBuffer.z += 1.0F;
}

void Camera::moveLeft() {
    movementBuffer.x -= 1.0F;
}

void Camera::moveRight() {
    movementBuffer.x += 1.0F;
}

void Camera::moveUp() {
    movementBuffer.y += 1.0F;
}

void Camera::moveDown() {
    movementBuffer.y -= 1.0F;
}

glm::mat4 Camera::getViewMatrix() const {
    return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() const {
    return projectionMatrix;
}
