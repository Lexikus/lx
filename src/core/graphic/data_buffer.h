#pragma once

#include <vector>

#include "buffer_element.h"

class DataBuffer {
private:
    unsigned int id_ = 0;
    int stride_ = 0;
    std::vector<BufferElement> layouts_ = {};
public:
    DataBuffer(const void* const data, unsigned int size);
    void bind() const;
    void unbind() const;
    void add_layout(BufferElement buffer_element);
    void configure() const;
    void configure_by_name(unsigned int program_id) const;
};
