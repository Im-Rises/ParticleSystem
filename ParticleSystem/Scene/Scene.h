#ifndef SCENE_H
#define SCENE_H

#include "Entity/ParticleGenerator/ParticleGeneratorBillboard.h"
#include "Entity/Cube/Cube.h"
#include "Entity/Billboard/Billboard.h"
#include "Camera/Camera.h"

class Scene {
public:
    Camera camera;

private:
    //    Billboard billboard;
    //    Cube cube;
    ParticleGeneratorBillboard particleGenerator;

public:
    Scene(int display_w, int display_h);

    ~Scene();

    void update(float deltaTime);

    void render();

public:
    void updateProjectionMatrix(int display_w, int display_h);
};

#endif // SCENE_H
