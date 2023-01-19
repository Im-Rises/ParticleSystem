#ifndef SCENE_H
#define SCENE_H

#include "Entity/ParticleGenerator/ParticleGenerator.h"
#include "Entity/Cube/Cube.h"
#include "Camera/Camera.h"

class Scene {
public:
    Camera camera;

private:
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
