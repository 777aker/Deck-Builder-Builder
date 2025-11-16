#pragma once

#include "dbbe/engine.hpp"

class UnitBuilder
{
public:
    UnitBuilder(Window *windowobj);
    ~UnitBuilder();
    void draw();
    void key(GLFWwindow *gl_window, int key, int scancode, int action, int mods);
    void mouse(GLFWwindow *gl_window, int button, int action, int mods);

private:
    Window *windowobj;
};