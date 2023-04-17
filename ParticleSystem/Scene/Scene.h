#ifndef SCENE_H
#define SCENE_H

#include "Entity/ParticleGenerator/ParticleGeneratorBillboard.h"
#include "Entity/Billboard/Billboard.h"
#include "Camera/Camera.h"

class Scene {
private:
    bool isPaused = false;

public:
    Camera camera;
    ParticleGeneratorBillboard particleGenerator;

    // private:
    //     Billboard billboard;
    //     Cube cube;

public:
    Scene(int display_w, int display_h);
    ~Scene();
    void update(float deltaTime);
    void render();

public:
    void updateProjectionMatrix(int display_w, int display_h);
    void togglePause();
};

#endif // SCENE_H
