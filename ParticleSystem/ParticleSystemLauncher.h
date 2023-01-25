#ifndef PARTICLE_EMISSION_H
#define PARTICLE_EMISSION_H

#include <memory>

#include "Scene/Scene.h"

constexpr char *PROJECT_NAME = "Particle Emission 3D";

constexpr char *PROJECT_VERSION = "0.5.0";

constexpr char *PROJECT_GITHUB = "https://github.com/Im-Rises/ParticleSystem";

struct GLFWwindow;

class ParticleSystemLauncher {
private:
    GLFWwindow *window;
    int display_w = 1280, display_h = 720;

    std::unique_ptr<Scene> scene;

    struct {
        float x = 0.45f;
        float y = 0.55f;
        float z = 0.60f;
        float w = 1.0f;
    } clear_color;

public:
    ParticleSystemLauncher();

    ~ParticleSystemLauncher();

    void start();

private:
    void handleInputs();

    void handleUi(float deltaTime);

    void updateGame(float deltaTime);

    void updateScreen();

//private:
//    void toggleWireframeMode();
};


#endif // PARTICLE_EMISSION_H
