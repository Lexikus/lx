#pragma once

#include <string>

#include "buffer_data_type.h"

class BufferElement {
private:
    BufferDataType type_ = BufferDataType::None;
    std::string name_;
    unsigned int size_ = 0;
    unsigned int count_ = 0;
    bool normalized_ = false;
public:
    BufferElement(BufferDataType type, std::string name, bool normalized = false);
    const std::string& get_name() const;
    unsigned int get_size() const;
    unsigned int get_count() const;
    bool is_normalized() const;
};

