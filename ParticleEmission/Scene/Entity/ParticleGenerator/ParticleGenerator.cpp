#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator() : Entity(
        "ParticleGenerator.vert",
        "ParticleGenerator.frag") {
    init();
}

void ParticleGenerator::init() {

}

ParticleGenerator::~ParticleGenerator() {
    destroy();
}

void ParticleGenerator::destroy() {

}

void ParticleGenerator::update(float deltaTime) {

}

void ParticleGenerator::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {

}
