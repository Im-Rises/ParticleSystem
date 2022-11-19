#ifndef PARTICLEEMISSION_H
#define PARTICLEEMISSION_H

struct GLFWwindow;

class ParticleEmission {
private:
    GLFWwindow* window;

public:
    ParticleEmission();

    ~ParticleEmission();

    void start();
};



#endif // PARTICLEEMISSION_H
