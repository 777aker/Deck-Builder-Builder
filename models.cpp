#include "models.hpp"

namespace models
{
    std::unique_ptr<lve::LveModel> createSquareModel(lve::LveDevice &device, glm::vec2 offset)
    {
        std::vector<lve::LveModel::Vertex> vertices = {
            {{-0.5f, -0.5f}},
            {{0.5f, 0.5f}},
            {{-0.5f, 0.5f}},
            {{-0.5f, -0.5f}},
            {{0.5f, -0.5f}},
            {{0.5f, 0.5f}},
        };
        for (auto &v : vertices)
        {
            v.position += offset;
        }
        return std::make_unique<lve::LveModel>(device, vertices);
    }
}