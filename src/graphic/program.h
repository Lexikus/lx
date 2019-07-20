#pragma once

#include <string>

#include <glm/glm.hpp>

#include "shader.h"

class Program {
private:
    unsigned int id_ { 0 };
    bool is_valid_ { true };
    std::string error_ { };
public:
    Program(std::string vertex_path, std::string fragment_path);
    Program(Shader& vertex_shader, Shader& fragment_shader);
    void bind() const;
    void unbind() const;
    bool is_valid() const;
    const std::string& get_error() const;
    unsigned int get_id() const;
    void set_bool(const std::string &name, bool value) const;
    void set_int(const std::string &name, int value) const;
    void set_float(const std::string &name, float value) const;
    void set_vec2(const std::string &name, const glm::vec2 &value) const;
    void set_vec2(const std::string &name, float x, float y) const;
    void set_vec3(const std::string &name, const glm::vec3 &value) const;
    void set_vec3(const std::string &name, float x, float y, float z) const;
    void set_vec4(const std::string &name, const glm::vec4 &value) const;
    void set_vec4(const std::string &name, float x, float y, float z, float w);
    void set_mat2(const std::string &name, const glm::mat2 &mat) const;
    void set_mat3(const std::string &name, const glm::mat3 &mat) const;
    void set_mat4(const std::string &name, const glm::mat4 &mat) const;
private:
    bool compile(Shader& vertex_shader, Shader& fragment_shader);
};
