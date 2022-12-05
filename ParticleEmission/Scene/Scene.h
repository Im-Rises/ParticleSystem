#ifndef SCENE_H
#define SCENE_H

#include "Entity/ParticleGenerator/ParticleGenerator.h"
#include "Entity/Cube/Cube.h"
#include "Entity/Camera/Camera.h"


class Scene {
private:
    Camera camera;
    ParticleGenerator particleGenerator;
    Cube cube;

public:
    Scene(int display_w, int display_h);

    ~Scene();

    void update(float deltaTime);

    void render();

public:
    void updateProjectionMatrix(int display_w, int display_h);
};

#endif // SCENE_H
