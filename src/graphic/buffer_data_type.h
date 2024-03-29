#pragma once

#include <glad/glad.h>

enum class BufferDataType {
    None = 0,
    Float,
    Float2,
    Float3,
    Float4,
    Mat3,
    Mat4,
    Int,
    Int2,
    Int3,
    Int4,
    Bool
};

int buffer_data_type_size(BufferDataType buffer_data_type);
unsigned int buffer_data_type_count(BufferDataType buffer_data_type);
unsigned int buffer_data_type_api_type(BufferDataType buffer_data_type);
