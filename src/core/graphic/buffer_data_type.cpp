#include "buffer_data_type.h"

unsigned int buffer_data_type_size(BufferDataType buffer_data_type){
    switch (buffer_data_type) {
        case BufferDataType::Float: return 4;
        case BufferDataType::Float2: return 4 * 2;
        case BufferDataType::Float3: return 4 * 3;
        case BufferDataType::Float4: return 4 * 4;
        case BufferDataType::Mat3: return 4 * 3 * 3;
        case BufferDataType::Mat4: return 4 * 4 * 4;
        case BufferDataType::Int: return 4;
        case BufferDataType::Int2: return 4 * 2;
        case BufferDataType::Int3: return 4 * 3;
        case BufferDataType::Int4: return 4 * 4;
        case BufferDataType::Bool: return 1;
    }

    return 0;
}