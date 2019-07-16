#pragma once

#include <glm/glm.hpp>
#include <memory>

#include "primitive.h"
#include "../graphic/vertex_array.h"
#include "../graphic/data_buffer.h"
#include "../graphic/index_buffer.h"

class Cube {
private:
    std::unique_ptr<VertexArray> vertex_array_;
    std::shared_ptr<DataBuffer> data_buffer_;
    std::shared_ptr<IndexBuffer> index_buffer_;
    glm::vec3 vertices_cube_[24];
    glm::ivec3 indices_cube_[12];
    glm::vec2 uvs_cube_[24];
    glm::vec4 color_cube_[24];
public:
    Cube();
    void bind();
    void unbind();
};

