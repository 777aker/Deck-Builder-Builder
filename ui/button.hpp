#pragma once

#include "dbbe/engine.hpp"
#include "dbbe/colors.hpp"

#include <string>

class Button
{
public:
    Button(void (*call)(), float xpos, float ypos, std::string words, color fill);
    ~Button();
    bool clicked(float xpos, float ypos);
    void draw_button();

private:
    void (*call)();
    float xpos;
    float ypos;
    float width;
    float height;
    color fill;
    std::string words;
};