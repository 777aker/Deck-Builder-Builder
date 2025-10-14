#pragma once

#include "lve_game_object.hpp"
#include "lve_window.hpp"

namespace lve
{
    class KeyboardMovementController
    {
    public:
        struct KeyMappings
        {
            int moveLeft = GLFW_KEY_A;
            int moveRight = GLFW_KEY_D;
            int moveUp = GLFW_KEY_W;
            int moveDown = GLFW_KEY_S;
        };

        void moveInPlaneXY(GLFWwindow *window, float dt, LveGameObject &gameObject);

        KeyMappings keys{};
        float moveSpeed{3.0f};
    };
}
