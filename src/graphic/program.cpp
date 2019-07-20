#include "program.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>

#include "shader.h"
#include "shader_type.h"

Program::Program(std::string vertex_path, std::string fragment_path) {
    Shader vertex_shader { vertex_path, ShaderType::Vertex };
    Shader fragment_shader { fragment_path, ShaderType::Fragment };

    Program(vertex_shader, fragment_shader);
}

Program::Program(Shader& vertex_shader, Shader& fragment_shader) {
    if(!vertex_shader.is_valid() || !fragment_shader.is_valid()){
        is_valid_ = false;
        error_ = "Vertex or fragment shader in program is invalid!\n\n";
        error_ += "VertexShader\n";
        error_ += "------------\n";
        error_ += vertex_shader.get_error();
        error_ += "\n==================================================\n";
        error_ += "FragmentShader\n";
        error_ += "--------------\n";
        error_ += fragment_shader.get_error();
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

    int success { 0 };
    char infoLog[1024] { };

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

unsigned int Program::get_id() const {
    return id_;
}

void Program::set_bool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
}

void Program::set_int(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void Program::set_float(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}

void Program::set_vec2(const std::string &name, const glm::vec2 &value) const {
    glUniform2fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
}

void Program::set_vec2(const std::string &name, float x, float y) const {
    glUniform2f(glGetUniformLocation(id_, name.c_str()), x, y);
}

void Program::set_vec3(const std::string &name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
}

void Program::set_vec3(const std::string &name, float x, float y, float z) const {
    glUniform3f(glGetUniformLocation(id_, name.c_str()), x, y, z);
}

void Program::set_vec4(const std::string &name, const glm::vec4 &value) const {
    glUniform4fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
}

void Program::set_vec4(const std::string &name, float x, float y, float z, float w) {
    glUniform4f(glGetUniformLocation(id_, name.c_str()), x, y, z, w);
}

void Program::set_mat2(const std::string &name, const glm::mat2 &mat) const {
    glUniformMatrix2fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Program::set_mat3(const std::string &name, const glm::mat3 &mat) const {
    glUniformMatrix3fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Program::set_mat4(const std::string &name, const glm::mat4 &mat) const {
    glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
