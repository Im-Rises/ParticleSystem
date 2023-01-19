#include "Scene.h"

Scene::Scene(int display_w, int display_h) : camera(display_w, display_h) {

}

Scene::~Scene() {

}

void Scene::update(float deltaTime) {
    camera.update(deltaTime);
    cube.update(deltaTime);
    particleGenerator.update(deltaTime);
}

void Scene::render() {
    cube.render(camera.getViewMatrix(), camera.getProjectionMatrix());
    particleGenerator.render(camera.getViewMatrix(), camera.getProjectionMatrix());
}

void Scene::updateProjectionMatrix(int display_w, int display_h) {
    camera.updateProjectionMatrix(display_w, display_h);
}
