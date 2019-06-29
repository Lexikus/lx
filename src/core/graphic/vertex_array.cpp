#include "vertex_array.h"

#include <glad/glad.h>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &id_);
}

void VertexArray::bind() {
    glBindVertexArray(id_);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}

