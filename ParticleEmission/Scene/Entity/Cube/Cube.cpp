#include "Cube.h"

#include <glm/glm.hpp>
#include <glad/glad.h>

Cube::Cube() : Entity("shaders/transform.vert", "shaders/transform.frag") {

}

//Cube::~Cube() {
//
//}

void Cube::update(float deltaTime) {
    // No component to update
}

void Cube::render() {
    // Matrix calculations
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(fov / 2), static_cast<float>(display_w) / static_cast<float>(display_h),
                                  0.1f, 100.0f);

    //Shader use
    shader.use();
    shader.setMat4("model",
                   glm::translate(model, glm::vec3(-transform.positionX, -transform.positionY, -transform.positionZ)));
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    // Draw
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
