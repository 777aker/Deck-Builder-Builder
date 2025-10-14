#include "keyboard_movement_controller.hpp"

namespace lve
{
    void KeyboardMovementController::moveInPlaneXY(GLFWwindow *window, float dt, LveGameObject &gameObject)
    {
        if (glfwGetKey(window, keys.moveUp) == GLFW_PRESS)
            gameObject.transform2d.translation.y -= dt * moveSpeed;
        if (glfwGetKey(window, keys.moveDown) == GLFW_PRESS)
            gameObject.transform2d.translation.y += dt * moveSpeed;
        if (glfwGetKey(window, keys.moveRight) == GLFW_PRESS)
            gameObject.transform2d.translation.x += dt * moveSpeed;
        if (glfwGetKey(window, keys.moveLeft) == GLFW_PRESS)
            gameObject.transform2d.translation.x -= dt * moveSpeed;
    }
}