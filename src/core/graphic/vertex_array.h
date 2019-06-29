#pragma once

class VertexArray
{
private:
    unsigned int id_ = 0;
public:
    VertexArray();
    void bind();
    void unbind();
};
