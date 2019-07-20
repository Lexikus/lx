#include "cube.h"

#include <array>
#include <memory>

#include "../graphic/vertex_array.h"
#include "../graphic/data_buffer.h"
#include "../graphic/buffer_data_type.h"
#include "../graphic/buffer_element.h"

Cube::Cube() {
    vertex_array_ = std::make_unique<VertexArray>();
    vertex_array_->bind();

    data_buffer_ = std::make_unique<DataBuffer>(data_.data(), sizeof(data_));
    BufferElement buffer_element_position {
        BufferDataType::Float3,
        "aPos"
    };

    BufferElement buffer_element_normal {
        BufferDataType::Float3,
        "aNor"
    };

    BufferElement buffer_element_uv {
        BufferDataType::Float2,
        "aUV"
    };

    BufferElement buffer_element_color {
        BufferDataType::Float4,
        "aCol"
    };

    data_buffer_->add_element(buffer_element_position);
    data_buffer_->add_element(buffer_element_normal);
    data_buffer_->add_element(buffer_element_uv);
    data_buffer_->add_element(buffer_element_color);
    data_buffer_->configure_by_index();

    index_buffer_ = std::make_unique<IndexBuffer>(indices_.data(), sizeof(indices_));
    vertex_array_->unbind();
}

void Cube::bind() {
    vertex_array_->bind();
}

void Cube::unbind() {
    vertex_array_->unbind();
}