#include "Camera.h"

Camera::Camera(int display_w, int display_h) {
    position = glm::vec3(0.0F, 0.0F, 3.0F);
//    rotation = glm::vec3(0.0F, 0.0F, 0.0F);
    updateViewMatrix();
    updateProjectionMatrix(display_w, display_h);
}

Camera::~Camera() {

}

void Camera::updateViewMatrix() {
    viewMatrix = glm::lookAt(position, position + cameraFrontBuffer, cameraUp);
}

void Camera::updateProjectionMatrix(int display_w, int display_h) {
    projectionMatrix = glm::perspective(glm::radians(fov / 2), (float) display_w / (float) display_h, nearPlane,
                                        farPlane);
}

void Camera::update(float deltaTime) {
    position += movementBuffer * movementSpeed * deltaTime;

    updateViewMatrix();

    movementBuffer = glm::vec3(0.0F);
}

glm::mat4 Camera::getViewMatrix() const {
    return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() const {
    return projectionMatrix;
}
