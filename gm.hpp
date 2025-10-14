#pragma once

#include "lve/lve_device.hpp"
#include "lve/lve_game_object.hpp"
#include "lve/lve_renderer.hpp"
#include "lve/lve_window.hpp"

#include <memory>
#include <vector>

namespace GTR
{
    class GameManager
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        GameManager();
        ~GameManager();

        GameManager(const GameManager &) = delete;
        GameManager &operator=(const GameManager &) = delete;

        void run();

    private:
        lve::LveWindow lveWindow{WIDTH, HEIGHT, "Vulkan Tutorial"};
        lve::LveDevice lveDevice{lveWindow};
        lve::LveRenderer lveRenderer{lveWindow, lveDevice};

        std::vector<lve::LveGameObject> gameObjects;
    };
}