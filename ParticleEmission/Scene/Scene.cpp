#include "Scene.h"

Scene::Scene(int display_w, int display_h) : camera(display_w, display_h) {

}

Scene::~Scene() {

}

void Scene::update(float deltaTime) {
//    particleGenerator.update(deltaTime);
    cube.update(deltaTime);
}

void Scene::render() {
//    particleGenerator.render(camera.getViewMatrix(), camera.getProjectionMatrix());
    cube.render(camera.getViewMatrix(), camera.getProjectionMatrix());
}

void Scene::updateProjectionMatrix(int display_w, int display_h) {
    camera.updateProjectionMatrix(display_w, display_h);
}
