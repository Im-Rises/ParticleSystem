#include "Cube.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Cube::Cube() : Entity("shaders/transform.vert", "shaders/transform.frag") {

}

//Cube::~Cube() {
//
//}

void Cube::update(float deltaTime) {
    // No component to update
}

void Cube::render(glm::mat4 cameraProjectionMatrix, glm::mat4 cameraViewMatrix) {
    //Shader use
    shader.use();
    shader.setMat4("model", glm::translate(model, transform.position));
    shader.setMat4("view", cameraViewMatrix);
    shader.setMat4("projection", cameraProjectionMatrix);

    // Draw
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

void Cube::updateModelMatrix() {
    model = glm::mat4(1.0F);
    model = glm::rotate(model, glm::radians(transform.rotation.x), glm::vec3(1.0F, 0.0F, 0.0F));
    model = glm::rotate(model, glm::radians(transform.rotation.y), glm::vec3(0.0F, 1.0F, 0.0F));
    model = glm::rotate(model, glm::radians(transform.rotation.z), glm::vec3(0.0F, 0.0F, 1.0F));
    model = glm::scale(model, transform.scale);
}
