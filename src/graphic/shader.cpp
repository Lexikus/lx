#include "shader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "shader_type.h"

Shader::Shader(std::string shader_path, ShaderType type) {
    std::string vertex_shader_code { read_from_file(shader_path) };

    if(!is_valid_) {
        return;
    }

    id_ = create(vertex_shader_code, type);
    is_valid_ = compile(id_);
}

bool Shader::is_valid() const {
    return is_valid_;
}

const std::string& Shader::get_error() const {
    return error_;
}

int Shader::get_id() const {
    return id_;
}

void Shader::destroy() const {
    glDeleteShader(id_);
}

std::string Shader::read_from_file(const std::string &path) {
    std::ifstream shader_file;
    shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        shader_file.open(path);

        std::stringstream shader_stream;
        // read file's buffer contents into streams
        shader_stream << shader_file.rdbuf();
        // close file handlers
        shader_file.close();

        // convert stream into string
        return shader_stream.str();
    } catch (std::ifstream::failure e) {
        is_valid_ = false;
        error_ = "shader file could not be read. Check path: \n";
        error_ += path;

        if(shader_file.is_open()){
            shader_file.close();
        }

        return "";
    }
}

unsigned int Shader::create(const std::string &code, ShaderType type) const {
    const char* shader_code { code.c_str() };
    unsigned int id { 0 };
    switch (type) {
        case ShaderType::Vertex:
            id = glCreateShader(GL_VERTEX_SHADER);
            break;
        case ShaderType::Fragment:
            id = glCreateShader(GL_FRAGMENT_SHADER);
            break;
    }
    glShaderSource(id, 1, &shader_code, NULL);
    return id;
}

bool Shader::compile(unsigned int id) {
    glCompileShader(id);

    int success { 0 };
    char infoLog[1024] { };

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(id, 1024, NULL, infoLog);
        error_ = "shader compilation failed: \n";
        error_ += infoLog;

        return false;
    }

    return true;
}
