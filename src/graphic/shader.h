#pragma once

#include <glad/glad.h>

#include <string>

#include "shader_type.h"

class Shader {
private:
    unsigned int id_ { 0 };
    std::string error_ { };
    bool is_valid_ { true };
public:
    Shader(std::string shader_path, ShaderType type);
    bool is_valid() const;
    const std::string &get_error() const;
    int get_id() const;
    void destroy() const;
private:
    std::string read_from_file(const std::string &path);
    unsigned int create(const std::string &code, ShaderType type) const;
    bool compile(unsigned int id);
};
