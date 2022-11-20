#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::update(float deltaTime) {
    particleGenerator.update(deltaTime);
}

void Scene::render() {
    particleGenerator.render();
}
