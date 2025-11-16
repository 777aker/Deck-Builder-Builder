#include "game_manager.hpp"

GameManager::GameManager(Window *windowobj)
{
    this->windowobj = windowobj;
    main_shader = CreateShaderProg("shaders/main.vert", "shaders/main.frag");

    render_loop();
}

GameManager::~GameManager() {}

void GameManager::init_main_menu()
{
    // std::unique_ptr<Text> tit = std::make_unique<Text>((float)(dim * 0.8), (float)(dim * 0.5), "Deck Builder Builder", midnight_blue, 16.0);
    // drawObjects.push_back(std::move(tit));
}

void GameManager::render_loop()
{
    init_main_menu();

    while (!glfwWindowShouldClose(windowobj->glwindow))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (gameState == MAIN_MENU)
        {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(main_shader);
            glUniform1d(glGetUniformLocation(main_shader, "dim"), dim);
            glUniform1d(glGetUniformLocation(main_shader, "asp"), asp);

            text.draw_text(main_shader, -dim * 0.9, dim * 0.7, "Deck Builder Builder", -1, sunflower, 0.5);
        }
        else if (gameState == UNIT_BUILDER)
        {
        }

        for (auto &drawObject : drawObjects)
        {
            drawObject->draw();
        }

        int err = glGetError();
        if (err)
        {
            fprintf(stderr, "[%s] %s\n", "display", gluErrorString(err));
        }
        glFlush();
        glfwSwapBuffers(windowobj->glwindow);
        glfwPollEvents();
    }
}

void GameManager::key(GLFWwindow *gl_window, int key, int scancode, int action, int mods)
{
    switch (key)
    {
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(gl_window, 1);
        break;
    }
}

void GameManager::mouse(GLFWwindow *gl_window, int button, int action, int mods)
{
}