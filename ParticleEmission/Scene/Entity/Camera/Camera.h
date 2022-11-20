#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    float fov = 90.0F;
    float nearPlane = 0.1F;
    float farPlane = 100.0F;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    glm::vec3 position;
    glm::vec3 rotation;

public:
    Camera(int display_w, int display_h);

    ~Camera();

    void updateViewMatrix();

    void updateProjectionMatrix(int display_w, int display_h);

public:
    [[nodiscard]] glm::mat4 getViewMatrix() const;

    [[nodiscard]] glm::mat4 getProjectionMatrix() const;

};


#endif //CAMERA_H
