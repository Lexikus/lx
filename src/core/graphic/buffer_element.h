#pragma once

#include <string>

#include "buffer_data_type.h"

class BufferElement {
private:
    std::string name_;
    BufferDataType type_ = BufferDataType::None;
    unsigned int size_ = 0;
    unsigned int offset_ = 0;
    bool normalized_ = false;
public:
    BufferElement(BufferDataType type, std::string name, bool normalized = false);
};

