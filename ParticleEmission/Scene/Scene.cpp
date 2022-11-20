#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::update(float deltaTime) {
//    particleGenerator.update(deltaTime);
    cube.update(deltaTime);
}

void Scene::render() {
//    particleGenerator.render();
    cube.render();
}
