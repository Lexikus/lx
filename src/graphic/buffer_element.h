#pragma once

#include <string>

#include <glad/glad.h>

#include "buffer_data_type.h"

class BufferElement {
private:
    std::string name_;
    int32_t size_ { 0 };
    unsigned int count_ { 0 };
    GLenum type_ { 0 };
    bool normalized_ { false };
public:
    BufferElement(BufferDataType type, std::string name, bool normalized = false);
    const std::string& get_name() const;
    int32_t get_size() const;
    unsigned int get_count() const;
    GLenum get_type() const;
    bool is_normalized() const;
};
