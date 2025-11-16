#pragma once

#include "dbbe/engine.hpp"
#include "unit_builder/unit_builder.hpp"
#include "ui/text.hpp"

#include <vector>
#include <memory>

enum GameState
{
    MAIN_MENU,
    UNIT_BUILDER,
};

class GameManager
{
public:
    GameManager(Window *Windowobj);
    ~GameManager();
    void key(GLFWwindow *gl_window, int key, int scancode, int action, int mods);
    void mouse(GLFWwindow *gl_window, int button, int action, int mods);

private:
    Window *windowobj;
    int main_shader;
    GameState gameState = MAIN_MENU;
    std::vector<std::unique_ptr<DrawObject>> drawObjects = {};

    UnitBuilder *unitBuilder;
    Text text{};

    void init_main_menu();
    void render_loop();
};