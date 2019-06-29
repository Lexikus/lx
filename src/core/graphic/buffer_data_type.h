#pragma once

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

unsigned int buffer_data_type_size(BufferDataType buffer_data_type);