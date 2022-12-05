#include "Camera.h"


Camera::Camera(int display_w, int display_h) {
    position = glm::vec3(0.0F, 0.0F, -5.0F);
    updateViewMatrix();
    updateProjectionMatrix(display_w, display_h);
}

Camera::~Camera() {

}

void Camera::updateViewMatrix() {
    viewMatrix = glm::mat4(1.0F);
    viewMatrix = glm::translate(viewMatrix, position);
    viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.x), glm::vec3(1.0F, 0.0F, 0.0F));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.y), glm::vec3(0.0F, 1.0F, 0.0F));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.z), glm::vec3(0.0F, 0.0F, 1.0F));
}

void Camera::updateProjectionMatrix(int display_w, int display_h) {
    projectionMatrix = glm::perspective(glm::radians(fov / 2), (float) display_w / (float) display_h, nearPlane,
                                        farPlane);
}

glm::mat4 Camera::getViewMatrix() const {
    return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() const {
    return projectionMatrix;
}
