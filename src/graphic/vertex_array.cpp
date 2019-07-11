#include "vertex_array.h"

#include <glad/glad.h>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &id_);
}

void VertexArray::bind() const {
    glBindVertexArray(id_);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}
