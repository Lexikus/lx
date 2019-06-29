#pragma once

#include <string>

#include "shader.h"

class Program
{
private:
    unsigned int id_ = 0;
    bool is_valid_ = true;
    std::string error_;
public:
    Program(std::string vertex_path, std::string fragment_path);
    Program(Shader& vertex_shader, Shader& fragment_shader);
    void bind();
    void unbind();
    bool compile(Shader& vertex_shader, Shader& fragment_shader);
};
