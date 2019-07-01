#pragma once

class Texture
{
private:
    unsigned int id_;
public:
    Texture();
    void bind();
    void unbind();
};
