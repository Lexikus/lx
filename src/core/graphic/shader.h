#pragma once

#include <glad/glad.h>

#include <string>

class Shader {
private:
    unsigned int id_ = 0;
    std::string error_;
    bool is_valid_ = true;
public:
    Shader(std::string shader_path);
    bool is_valid();
    const std::string &get_error();
    int get_id();
    void destroy();
private:
    std::string read_from_file(const std::string &path);
    unsigned int create(const std::string &code);
    bool compile(unsigned int id);
};
