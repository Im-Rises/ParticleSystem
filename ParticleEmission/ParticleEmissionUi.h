#ifndef PARTICLEEMISSION_H
#define PARTICLEEMISSION_H

#include "Scene.h"

#define PROJECT_NAME "Particle Emission 3D"

#define VERSION_MAJOR "0"
#define VERSION_MINOR "4"
#define VERSION_PATCH "1"

#define PROJECT_VERSION VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH

#define PROJECT_GITHUB "https://github.com/Im-Rises/ParticleEmission"

struct GLFWwindow;

class ParticleEmissionUi {
private:
    GLFWwindow *window;

    Scene scene;

    struct {
        float x = 0.45f;
        float y = 0.55f;
        float z = 0.60f;
        float w = 1.0f;
    } clear_color;

public:
    ParticleEmissionUi();

    ~ParticleEmissionUi();

    void start();

private:
    void handleInputs();

    void handleUi();

    void updateGame();

    void updateScreen();
};


#endif // PARTICLEEMISSION_H
