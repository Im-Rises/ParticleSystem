#include "InputManager.h"

double InputManager::lastMouseX = 0.0;
double InputManager::lastMouseY = 0.0;

void InputManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

//    switch (action)
//    {
//        case GLFW_PRESS: {
//            keyPressed(window, key, engine);
//            break;
//        }
//        case GLFW_RELEASE: {
//            keyReleased(window, key, engine);
//            break;
//        }
//        case GLFW_REPEAT: {
//            keyRepeated(window, key, engine);
//            break;
//        }
//        default: {
//            std::cout << "Unknown keyboard action" << std::endl;
//            break;
//        }
//    }
}

bool InputManager::isForwardKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
}

bool InputManager::isBackwardKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
}

bool InputManager::isLeftKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
}

bool InputManager::isRightKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
}

bool InputManager::isUpKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS;//GLFW_KEY_PAGE_UP
}

bool InputManager::isDownKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;//GLFW_KEY_PAGE_DOWN
}

void InputManager::getMouseMovement(GLFWwindow *window, double &xMovement, double &yMovement, bool isMovementEnable) {
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    if (isMovementEnable) {
        xMovement = x - lastMouseX;
        yMovement = lastMouseY - y;
    }
    lastMouseX = x;
    lastMouseY = y;
}

bool InputManager::isKeyMouseMovementPressed(GLFWwindow *window) {
    return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
}
