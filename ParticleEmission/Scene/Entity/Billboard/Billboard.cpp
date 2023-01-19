#include "Billboard.h"

#include <glad/glad.h>

Billboard::Billboard()
        : Entity("shaders/Billboard.vert", "shaders/Billboard.frag") {
    create();
    position = glm::vec3(1.0F, 0.0F, 0.0F);
    updateModelMatrix();
}

void Billboard::create() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    shader.use();
}

Billboard::~Billboard() {
    destroy();
}

void Billboard::destroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Billboard::update(float deltaTime) {

}

void Billboard::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {
    //Shader
    shader.use();
    shader.setMat4("view", cameraViewMatrix);
    shader.setMat4("projection", cameraProjectionMatrix);
    shader.setMat4("model", modelMatrix);
    shader.setVec3("CameraRight_worldspace",
                   glm::vec3(cameraViewMatrix[0][0], cameraViewMatrix[1][0], cameraViewMatrix[2][0]));
    shader.setVec3("CameraUp_worldspace",
                   glm::vec3(cameraViewMatrix[0][1], cameraViewMatrix[1][1], cameraViewMatrix[2][1]));
    shader.setVec3("BillboardPos", glm::vec3(0, 0, 0));
    shader.setVec2("BillboardSize", glm::vec2(0.1f, 0.1f));

    // Draw
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei) vertices.size());
}
