#include "ParticleSystemLauncher.h"

#include <iostream>
#include <cstdio>
#include <glad/glad.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "InputManager.h"

#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif

#include <GLFW/glfw3.h>
#include <cstdlib>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

ParticleSystemLauncher::ParticleSystemLauncher() {
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        exit(1);

        // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 330
    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.3 + GLSL 330
    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // Required on Mac
#else
    // GL 3.3 + GLSL 330
    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // 3.0+ only
#endif

    // Create window with graphics context
    window = glfwCreateWindow(display_w, display_h, PROJECT_NAME.data(), nullptr, nullptr);
    if (window == nullptr)
        exit(1);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    //    // Initialize GLFW callbacks
    //    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, InputManager::key_callback);
    //    glfwSetScrollCallback(window, InputManager::scroll_callback);
    //    glfwSetCursorPosCallback(window, InputManager::cursor_position_callback);
    //    glfwSetMouseButtonCallback(window, InputManager::mouse_button_callback);

    // Center window
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    auto xPos = (mode->width - display_w) / 2;
    auto yPos = (mode->height - display_h) / 2;
    glfwSetWindowPos(window, xPos, yPos);

    // Initialize OpenGL loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        exit(1);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;   // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
    // io.ConfigViewportsNoAutoMerge = true;
    // io.ConfigViewportsNoTaskBarIcon = true;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    glEnable(GL_DEPTH_TEST);
}

ParticleSystemLauncher::~ParticleSystemLauncher() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

void ParticleSystemLauncher::start() {
    // Create the scene
    scene = std::make_unique<Scene>(display_w, display_h);

    // Variables for the main loop
    float deltaTime = 0.0F;

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        deltaTime = ImGui::GetIO().DeltaTime;

        handleInputs();

        handleUi(deltaTime);

        updateGame(deltaTime);

        updateScreen();
    }
}

void ParticleSystemLauncher::handleInputs() {
    glfwPollEvents();

    /* Read inputs and update states (buffers) */
    if (InputManager::isLeftKeyPressed(window))
        scene->camera.moveLeft();

    if (InputManager::isRightKeyPressed(window))
        scene->camera.moveRight();

    if (InputManager::isForwardKeyPressed(window))
        scene->camera.moveForward();

    if (InputManager::isBackwardKeyPressed(window))
        scene->camera.moveBackward();

    if (InputManager::isUpKeyPressed(window))
        scene->camera.moveUp();

    if (InputManager::isDownKeyPressed(window))
        scene->camera.moveDown();

    if (InputManager::isPauseKeyPressed(window))
        scene->togglePause();

    double x = 0, y = 0;
    InputManager::getMouseMovement(window, x, y, InputManager::isKeyMouseMovementPressed(window));
    scene->camera.processMouseMovement((float)x, (float)y);
}

void ParticleSystemLauncher::handleUi(float deltaTime) {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    {
        ImGui::Begin("Window info");
        ImGui::Text("%.3f ms/frame (%.1f FPS)", deltaTime, 1.0f / deltaTime);
        ImGui::Text("Window width: %d", display_w);
        ImGui::Text("Window height: %d", display_h);
        ImGui::End();
    }

    {
        ImGui::Begin("Camera settings");

        static bool wireframe = false;
        ImGui::TextColored(ImVec4(1.0F, 0.0F, 1.0F, 1.0F), "View settings");
        ImGui::Checkbox("Wireframe", &wireframe);
        if (wireframe)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        else
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        ImGui::NewLine();

        ImGui::TextColored(ImVec4(1.0F, 0.0F, 1.0F, 1.0F), "Camera settings");

        ImGui::Text("Position:");
        ImGui::DragFloat3("##position", (float*)&scene->camera.position);

        ImGui::NewLine();
        ImGui::Text("Pitch:");
        ImGui::Checkbox("Pitch constrained", &scene->camera.constrainPitch);
        ImGui::DragFloat("##pitch", &scene->camera.pitch);

        ImGui::Text("Yaw:");
        ImGui::DragFloat("##yaw", &scene->camera.yaw);

        ImGui::NewLine();
        ImGui::Text("FOV:");
        ImGui::DragFloat("##fov", &scene->camera.fov);

        ImGui::NewLine();
        ImGui::Text("Near plane:");
        ImGui::DragFloat("##near", &scene->camera.nearPlane);

        ImGui::Text("Far plane:");
        ImGui::DragFloat("##far", &scene->camera.farPlane);

        ImGui::NewLine();
        ImGui::Text("Speed:");
        ImGui::DragFloat("##speed", &scene->camera.movementSpeed);

        ImGui::Text("Sensitivity: ");
        ImGui::DragFloat("##sensitivity", &scene->camera.rotationSpeed);

        ImGui::End();
    }

    {
        ImGui::Begin("Particle settings");

        ImGui::TextColored(ImVec4(1.0F, 0.0F, 1.0F, 1.0F), "Reset particles");
        ImGui::Button("Reset");
        if (ImGui::IsItemClicked())
        {
            scene->particleGenerator.reset();
        }
        ImGui::NewLine();

        ImGui::TextColored(ImVec4(1.0F, 0.0F, 1.0F, 1.0F), "Settings");
        ImGui::Text("Origin:");
        ImGui::DragFloat3("##origin", (float*)&scene->particleGenerator.position);

        ImGui::NewLine();
        ImGui::Text("Forces sum:");
        ImGui::DragFloat3("##forces", (float*)&scene->particleGenerator.sumForces);

        ImGui::NewLine();
        ImGui::Checkbox("Randomize spread", &scene->particleGenerator.randomizePosition);
        if (scene->particleGenerator.randomizePosition)
        {
            ImGui::Text("Particles min spread:");
            ImGui::DragFloat3("##minSpread", (float*)&scene->particleGenerator.minSpread, 0.1f);
            ImGui::Text("Particles max spread:");
            ImGui::DragFloat3("##maxSpread", (float*)&scene->particleGenerator.maxSpread, 0.1f);
        }

        ImGui::NewLine();
        ImGui::Checkbox("Randomize lifetime", &scene->particleGenerator.randomizeLifeTime);
        if (scene->particleGenerator.randomizeLifeTime)
        {
            ImGui::Text("Particle min lifetime:");
            ImGui::DragFloat("##minLifetime", &scene->particleGenerator.minLifeTime, 0.1f);
            ImGui::Text("Particle max lifetime:");
            ImGui::DragFloat("##maxLifetime", &scene->particleGenerator.maxLifeTime, 0.1f);
        }
        else
        {
            ImGui::Text("Particle lifetime:");
            ImGui::DragFloat("##lifetime", &scene->particleGenerator.fixedLifeTime, 0.1f);
        }

        ImGui::NewLine();
        ImGui::Checkbox("Randomize initial velocity", &scene->particleGenerator.randomizeInitialVelocity);
        if (scene->particleGenerator.randomizeInitialVelocity)
        {
            ImGui::Text("Minimum inital velocity:");
            ImGui::DragFloat3("##minInitialVelocity", (float*)&scene->particleGenerator.minInitialVelocity);
            ImGui::Text("Maximum inital velocity:");
            ImGui::DragFloat3("##maxInitialVelocity", (float*)&scene->particleGenerator.maxInitialVelocity);
        }
        else
        {
            ImGui::Text("Initial velocity:");
            ImGui::DragFloat3("##initialVelocity", (float*)&scene->particleGenerator.fixedInitialVelocity);
        }

        ImGui::NewLine();
        ImGui::Checkbox("Randomize scale", &scene->particleGenerator.randomizeScale);
        if (scene->particleGenerator.randomizeScale)
        {
            ImGui::Text("Particle min scale:");
            ImGui::DragFloat2("##minScale", (float*)&scene->particleGenerator.minScale, 0.1f);
            ImGui::Text("Particle max scale:");
            ImGui::DragFloat2("##maxScale", (float*)&scene->particleGenerator.maxScale, 0.1f);
        }
        else
        {
            ImGui::Text("Particle scale:");
            ImGui::DragFloat2("##scale", (float*)&scene->particleGenerator.fixedScale, 0.1f);
        }

        ImGui::NewLine();
        ImGui::Checkbox("Randomize color", &scene->particleGenerator.randomizeColor);
        if (scene->particleGenerator.randomizeColor)
        {
            ImGui::Text("Particle min color:");
            ImGui::ColorEdit3("##minColor", (float*)&scene->particleGenerator.minColor);
            ImGui::Text("Particle max color:");
            ImGui::ColorEdit3("##maxColor", (float*)&scene->particleGenerator.maxColor);
        }
        else
        {
            ImGui::Text("Particle color:");
            ImGui::ColorEdit3("##color", (float*)&scene->particleGenerator.fixedColor);
        }

        ImGui::End();
    }
}

void ParticleSystemLauncher::updateGame(float deltaTime) {
    scene->update(deltaTime);
}

void ParticleSystemLauncher::updateScreen() {
    ImGui::Render();
    glfwGetFramebufferSize(window, &display_w, &display_h);
    scene->updateProjectionMatrix(display_w, display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w,
        clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    scene->render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }

    glfwSwapBuffers(window);
}
