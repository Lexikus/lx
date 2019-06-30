#include "data_buffer.h"

#include <glad/glad.h>

#include <iostream>

#include "buffer_element.h"

DataBuffer::DataBuffer(float* data, unsigned int size) {
    glGenBuffers(1, &id_);
    glBindBuffer(GL_ARRAY_BUFFER, id_);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void DataBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void DataBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DataBuffer::add_layout(BufferElement buffer_element) {
    stride_ += buffer_element.get_size();
    layouts_.push_back(buffer_element);
}

void DataBuffer::configure() {
    unsigned int layout_position = 0;
    unsigned int offset = 0;

    for (const BufferElement& element : layouts_) {
        glVertexAttribPointer(layout_position, element.get_count(), GL_FLOAT, element.is_normalized(), stride_, (void *)offset);
        glEnableVertexAttribArray(layout_position);
        layout_position++;
        offset += element.get_size();
    }
}
