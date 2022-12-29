#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>

class InputManager {
public:
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
};


#endif //INPUTMANAGER_H
