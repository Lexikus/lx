#pragma once

class IndexBuffer {
private:
    unsigned int id_ = 0;
public:
    IndexBuffer(const void* const data, size_t size);
    void bind() const;
    void unbind() const;
};
