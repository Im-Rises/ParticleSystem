#ifndef SCENE_H
#define SCENE_H

#include "Entity/ParticleGenerator/ParticleGenerator.h"

class Scene {
private:
    ParticleGenerator particleGenerator;

public:
    Scene();

    ~Scene();

    void update(float deltaTime);

    void render();
};

#endif // SCENE_H
