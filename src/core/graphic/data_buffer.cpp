#include "data_buffer.h"

#include <cstdint>

#include <glad/glad.h>

#include "buffer_element.h"

DataBuffer::DataBuffer(const void* const data, unsigned int size) {
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

void DataBuffer::add_element(BufferElement buffer_element) {
    stride_ += buffer_element.get_size();
    layouts_.push_back(buffer_element);
}

void DataBuffer::configure_by_index() const {
    glBindBuffer(GL_ARRAY_BUFFER, id_);

    unsigned int layout_position = 0;
    unsigned int offset = 0;

    for (const BufferElement& element : layouts_) {
        glVertexAttribPointer(
            layout_position,
            element.get_count(),
            element.get_type(),
            element.is_normalized(),
            stride_,
            static_cast<const char*>(0) + offset
        );

        glEnableVertexAttribArray(layout_position);
        layout_position++;
        offset += element.get_size();
    }
}

void DataBuffer::configure_by_name(unsigned int program_id) const {
    glBindBuffer(GL_ARRAY_BUFFER, id_);

    unsigned int offset = 0;

    for (const BufferElement& element : layouts_) {
        unsigned int position = glGetAttribLocation(program_id, element.get_name().c_str());
        glVertexAttribPointer(
            position,
            element.get_count(),
            element.get_type(),
            element.is_normalized(),
            stride_,
            static_cast<const char*>(0) + offset
        );

        glEnableVertexAttribArray(position);
        offset += element.get_size();
    }
}
