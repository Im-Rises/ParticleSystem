#ifndef PARTICLEEMISSION_H
#define PARTICLEEMISSION_H

struct GLFWwindow;

class ParticleEmissionUi {
private:
    GLFWwindow* window;

public:
    ParticleEmissionUi();

    ~ParticleEmissionUi();

    void start();
};



#endif // PARTICLEEMISSION_H
