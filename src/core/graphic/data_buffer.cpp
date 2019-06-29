#include "data_buffer.h"

#include <glad/glad.h>

#include <array>

DataBuffer::DataBuffer() {
    glGenBuffers(1, &id_);
}
