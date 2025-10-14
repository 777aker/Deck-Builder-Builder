#pragma once

#include "lve/lve_device.hpp"
#include "lve/lve_game_object.hpp"
#include "lve/lve_pipeline.hpp"

#include <memory>
#include <vector>

namespace lve
{
    class RenderSystem
    {
    public:
        RenderSystem(LveDevice &device, VkRenderPass renderPass);
        ~RenderSystem();

        RenderSystem(const RenderSystem &) = delete;
        RenderSystem &operator=(const RenderSystem &) = delete;

        void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<LveGameObject> &gameObjects);

    private:
        void createPipelineLayout();
        void createPipeline(VkRenderPass renderPass);

        LveDevice &lveDevice;

        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
    };
}