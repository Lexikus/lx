#include "buffer_element.h"

#include <string>

#include "buffer_data_type.h"

BufferElement::BufferElement(BufferDataType type, std::string name, bool normalized)
: type_ { type }, name_ { name }, size_ { buffer_data_type_size(type) }, normalized_ {normalized} {

}
