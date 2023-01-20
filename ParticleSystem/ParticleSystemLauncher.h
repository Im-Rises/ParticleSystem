#ifndef PARTICLEEMISSION_H
#define PARTICLEEMISSION_H

#include <memory>

#include "Scene/Scene.h"

#define PROJECT_NAME "Particle Emission 3D"

#define VERSION_MAJOR "0"
#define VERSION_MINOR "4"
#define VERSION_PATCH "1"

#define PROJECT_VERSION VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH

#define PROJECT_GITHUB "https://github.com/Im-Rises/ParticleSystem"

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

private:
    void toggleWireframeMode();
};


#endif // PARTICLEEMISSION_H
