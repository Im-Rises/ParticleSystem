#include "Scene.h"

Scene::Scene(int display_w, int display_h) : camera(display_w, display_h), particleGenerator(particlesCount) {
}

Scene::~Scene() {
}

void Scene::update(float deltaTime) {
    camera.update(deltaTime);

    if (isPaused)
    {
        return;
    }
    //    cube.update(deltaTime);
    //    billboard.update(deltaTime);
    particleGenerator.update(deltaTime);
}

void Scene::render() {
    //    cube.render(camera.getViewMatrix(), camera.getProjectionMatrix());
    //    billboard.render(camera.getViewMatrix(), camera.getProjectionMatrix());
    particleGenerator.render(camera.getViewMatrix(), camera.getProjectionMatrix());
}

void Scene::updateProjectionMatrix(int display_w, int display_h) {
    camera.updateProjectionMatrix(display_w, display_h);
}

void Scene::togglePause() {
    isPaused = !isPaused;
}

void Scene::restartParticlesGenerator() {
    //    this->particlesCount = particlesCount;
    //    particleGenerator.destroy();
    //    particleGenerator = ParticleGeneratorBillboard(particlesCount);
}
