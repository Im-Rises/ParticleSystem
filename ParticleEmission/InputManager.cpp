#include "InputManager.h"

void InputManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
//    auto* engine = (ParticleEngineLauncher*)glfwGetWindowUserPointer(window);

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
    return glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS;
}

bool InputManager::isDownKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS;
}
