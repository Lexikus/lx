#include "buffer_element.h"

#include <string>

#include "buffer_data_type.h"

BufferElement::BufferElement(BufferDataType type, std::string name, bool normalized):
type_ { type },
name_ { name },
size_ { buffer_data_type_size(type) },
count_ { buffer_data_type_count(type) },
normalized_ { normalized } { }

const std::string& BufferElement::get_name() const {
    return name_;
}

unsigned int BufferElement::get_size() const {
    return size_;
}

unsigned int BufferElement::get_count() const {
    return count_;
}

bool BufferElement::is_normalized() const {
    return normalized_;
}
