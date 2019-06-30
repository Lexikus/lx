#include "program.h"

#include <glad/glad.h>
#include <string>

#include "shader.h"
#include "shader_type.h"

Program::Program(std::string vertex_path, std::string fragment_path) {
    Shader vertex_shader = { vertex_path, ShaderType::Vertex };
    Shader fragment_shader = { fragment_path, ShaderType::Fragment };

    Program(vertex_shader, fragment_shader);
}

Program::Program(Shader& vertex_shader, Shader& fragment_shader) {
    if(!vertex_shader.is_valid() || !fragment_shader.is_valid()){
        is_valid_ = false;
        error_ = "shaders are not valid";
        return;
    }

    is_valid_ = compile(vertex_shader, fragment_shader);
}

void Program::bind() const {
    glUseProgram(id_);
}

void Program::unbind() const {
    glUseProgram(0);
}

bool Program::compile(Shader& vertex_shader, Shader& fragment_shader) {
    id_ = glCreateProgram();
    glAttachShader(id_, vertex_shader.get_id());
    glAttachShader(id_, fragment_shader.get_id());
    glLinkProgram(id_);

    int success = 0;
    char infoLog[1024];

    glGetProgramiv(id_, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id_, 1024, NULL, infoLog);
        error_ = "program compilation failed: \n";
        error_.append(infoLog);

        return false;
    }

    vertex_shader.destroy();
    fragment_shader.destroy();

    return true;
}

bool Program::is_valid() const {
    return is_valid_;
}

const std::string& Program::get_error() const {
    return error_;
}
