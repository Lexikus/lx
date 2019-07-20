#pragma once

#include <string>

class Texture
{
private:
    unsigned int id_ { 0 };
    unsigned int width_ { 0 };
    unsigned int height_ { 0 };
public:
    Texture(std::string path);
    void bind() const;
    void unbind() const;
};
