#ifndef PARTICLE_EMISSION_H
#define PARTICLE_EMISSION_H

#include <memory>
#include <string_view>

constexpr const std::string_view PROJECT_NAME = "Particle System";

constexpr const std::string_view PROJECT_VERSION = "1.4.0";

constexpr const std::string_view PROJECT_GITHUB = "https://github.com/Im-Rises/ParticleSystem";

constexpr const std::string_view PROJECT_AUTHOR = "Im-Rises (Quentin Morel)";

class Scene;

struct GLFWwindow;

class ParticleSystemLauncher {
private:
    GLFWwindow* window;
    int display_w = 1280, display_h = 720;
    float fixedDeltaTime = 1.0F / 50.0F;

    std::unique_ptr<Scene> scene;

    struct {
        float x = 0.45F;
        float y = 0.55F;
        float z = 0.60F;
        float w = 1.0F;
    } clear_color;

public:
    ParticleSystemLauncher();

    ~ParticleSystemLauncher();

    void start();

private:
    void handleInputs();

    void handleUi(float deltaTime);

    void updateGame(float deltaTime);
    void fixedUpdateGame(float deltaTime);

    void updateScreen();

private:
    std::string_view getOpenGLVendor();
    std::string_view getOpenGLVersion();
    std::string_view getGLSLVersion();
    std::string getGLFWVersion();
    std::string_view getGladVersion();
    std::string getImGuiVersion();
    std::string getGLMVersion();
};


#endif // PARTICLE_EMISSION_H
