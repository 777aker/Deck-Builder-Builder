#pragma once

#include "dbbe/engine.hpp"
#include "dbbe/colors.hpp"

#include <string>
#include <map>
#include <glm/glm.hpp>

struct Character
{
    unsigned int TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    unsigned int Advance;
};

class Text
{
public:
    Text();
    ~Text();
    void draw_text(int shader, float xpos, float ypos, std::string words, float width, color fill, float size);

private:
    std::map<char, Character> Characters;
    unsigned int VAO, VBO;
};