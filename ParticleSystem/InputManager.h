#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>

class InputManager {
private:
    static double lastMouseX, lastMouseY;

public:
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

public:
    static bool isForwardKeyPressed(GLFWwindow *window);

    static bool isBackwardKeyPressed(GLFWwindow *window);

    static bool isLeftKeyPressed(GLFWwindow *window);

    static bool isRightKeyPressed(GLFWwindow *window);

    static bool isUpKeyPressed(GLFWwindow *window);

    static bool isDownKeyPressed(GLFWwindow *window);

public:
    static void getMouseMovement(GLFWwindow *window, double &xMovement, double &yMovement, bool isMovementEnable);

    static bool isKeyMouseMovementPressed(GLFWwindow *window);
};

#endif //INPUTMANAGER_H
