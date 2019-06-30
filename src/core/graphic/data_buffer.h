#pragma once

#include <vector>

#include "buffer_element.h"

class DataBuffer {
private:
    unsigned int id_ = 0;
    unsigned int stride_ = 0;
    std::vector<BufferElement> layouts_ = {};
public:
    DataBuffer(float* data, unsigned int size);
    void bind();
    void unbind();
    void add_layout(BufferElement buffer_element);
    void configure();
};
