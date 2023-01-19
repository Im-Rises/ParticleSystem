#include "InputManager.h"

void InputManager::cursor_position_callback(GLFWwindow *window, double xPos, double yPos) {
//    if (mouseRightButtonPressed)
//    {
//        auto* engine = (PhysicalEngineLauncher*)glfwGetWindowUserPointer(window);
//        Camera* camera = engine->scene->getCameraPtr();
//        float xOffset = static_cast<float>(xPos) - mouseLastPosX;
//        float yOffset = mouseLastPosY - static_cast<float>(yPos);
//        camera->processMouseMovement(xOffset, yOffset);
//    }
//    mouseLastPosX = static_cast<float>(xPos);
//    mouseLastPosY = static_cast<float>(yPos);
}

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
    return glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS;//GLFW_KEY_PAGE_UP
}

bool InputManager::isDownKeyPressed(GLFWwindow *window) {
    return glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;//GLFW_KEY_PAGE_DOWN
}
