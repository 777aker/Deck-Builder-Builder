#include "first_app.hpp"

#include "simple_render_system.hpp"
#include "keyboard_movement_controller.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <stdexcept>
#include <array>
#include <chrono>
#include <cassert>

namespace lve
{

  FirstApp::FirstApp()
  {
    loadGameObjects();
  }

  FirstApp::~FirstApp() {}

  void FirstApp::run()
  {
    SimpleRenderSystem simpleRenderSystem{lveDevice, lveRenderer.getSwapChainRenderPass()};

    auto currentTime = std::chrono::high_resolution_clock::now();
    KeyboardMovementController triangleControl{};

    while (!lveWindow.shouldClose())
    {
      glfwPollEvents();

      auto newTime = std::chrono::high_resolution_clock::now();
      float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
      currentTime = newTime;

      triangleControl.moveInPlaneXY(lveWindow.getGLFWwindow(), deltaTime, gameObjects[0]);

      if (glfwGetMouseButton(lveWindow.getGLFWwindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
      {
        double xpos, ypos;
        glfwGetCursorPos(lveWindow.getGLFWwindow(), &xpos, &ypos);
        printf("x: %f, y: %f\n", xpos, ypos);
      }

      if (auto commandBuffer = lveRenderer.beginFrame())
      {
        lveRenderer.beginSwapChainRenderPass(commandBuffer);
        simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects);
        lveRenderer.endSwapChainRenderPass(commandBuffer);
        lveRenderer.endFrame();
      }
    }

    vkDeviceWaitIdle(lveDevice.device());
  }

  void FirstApp::loadGameObjects()
  {
    std::vector<LveModel::Vertex> vertices{
        {{0.0f, -0.5f}, {0.0f, 0.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 0.0f, 0.0f}},
        {{-0.5f, 0.5f}, {0.0f, 0.0f, 0.0f}}};
    auto lveModel = std::make_shared<LveModel>(lveDevice, vertices);

    auto triangle = LveGameObject::createGameObject();
    triangle.model = lveModel;
    triangle.color = {0.1f, 0.8f, 0.1f};
    triangle.transform2d.translation.x = 0.2f;
    triangle.transform2d.scale = {0.8f, 1.0f};
    triangle.transform2d.rotation = 0.25f * glm::two_pi<float>();

    gameObjects.push_back(std::move(triangle));
  }

}