#include "data_buffer.h"

#include <glad/glad.h>

#include "buffer_element.h"

DataBuffer::DataBuffer(float* data, unsigned int size) {
    glGenBuffers(1, &id_);
    glBindBuffer(GL_ARRAY_BUFFER, id_);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void DataBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void DataBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DataBuffer::add_layout(BufferElement buffer_element) {
    stride_ += buffer_element.get_size();
    layouts_.push_back(buffer_element);
}

void DataBuffer::configure() const {
    unsigned int layout_position = 0;
    size_t offset = 0;

    for (const BufferElement& element : layouts_) {
        glVertexAttribPointer(
            layout_position,
            element.get_count(),
            element.get_type(),
            element.is_normalized(),
            stride_,
            (void*)offset
        );

        glEnableVertexAttribArray(layout_position);
        layout_position++;
        offset += element.get_size();
    }
}
