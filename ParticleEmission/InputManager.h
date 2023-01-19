#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>

class InputManager {
public:
    static void cursor_position_callback(GLFWwindow *window, double xPos, double yPos);

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

public:
    static bool isForwardKeyPressed(GLFWwindow *window);

    static bool isBackwardKeyPressed(GLFWwindow *window);

    static bool isLeftKeyPressed(GLFWwindow *window);

    static bool isRightKeyPressed(GLFWwindow *window);

    static bool isUpKeyPressed(GLFWwindow *window);

    static bool isDownKeyPressed(GLFWwindow *window);
};

#endif //INPUTMANAGER_H
