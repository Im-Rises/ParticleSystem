#include "Entity.h"

#include <glm/gtc/matrix_transform.hpp>
//#include <glad/glad.h>
//#include <stb/stb_image.h>
//#include <iostream>

Entity::Entity(const std::string &vertexShaderPath, const std::string &fragmentShaderPath) : shader(
        vertexShaderPath.c_str(),
        fragmentShaderPath.c_str()) {
    updateModelMatrix();
}


Entity::~Entity() {
}

void Entity::updateModelMatrix() {
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0F, 0.0F, 0.0F));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0F, 1.0F, 0.0F));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0F, 0.0F, 1.0F));
    modelMatrix = glm::scale(modelMatrix, scale);
}

//void Entity::loadTexture(const std::string_view &texturePath) {
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//
//    // Set the texture wrapping/filtering options (on the currently bound texture object)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    // Load and generate the texture
//    int width, height, nrChannels;
//    unsigned char *data = stbi_load(texturePath.data(), &width, &height, &nrChannels, 0);
//    if (data) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    } else {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//}
