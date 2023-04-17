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
    std::string_view getOpenGLVendor();
    std::string_view getOpenGLVersion();
    std::string_view getGLSLVersion();
    std::string getGLFWVersion();
    std::string_view getGladVersion();
    std::string getImGuiVersion();
    std::string getGLMVersion();
};


#endif // PARTICLE_EMISSION_H
