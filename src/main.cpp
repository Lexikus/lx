#include <iostream>
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "core/graphic/program.h"
#include "core/graphic/context.h"
#include "core/graphic/shader.h"
#include "core/graphic/shader_type.h"
#include "core/graphic/window.h"
#include "core/graphic/vertex_array.h"
#include "core/graphic/buffer_data_type.h"
#include "core/graphic/buffer_element.h"
#include "core/graphic/data_buffer.h"
#include "core/graphic/index_buffer.h"

// settings
const short WIDTH = 800;
const short HEIGHT = 800;
const std::string TITLE = "OPENGL";

glm::vec3 vertices_triangle[] = {
    { 1.0,  1.0, 0.0 },
    { 1.0, -1.0, 0.0 },
    {-1.0, -1.0, 0.0 },
};

glm::vec4 vertices_color[] = {
    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
};

glm::ivec3 index_triangle[] = {
    { 0, 1, 2 }
};

int main() {
    Window window = {
        TITLE,
        WIDTH,
        HEIGHT
    };

    if(!window.init()) {
        window.terminate();
        return 1;
    }

    Context context = {};
    if (!context.init()) {
        window.terminate();
        return 1;
    }

    Shader vertex_shader = { "assets/shaders/vert.vertex.glsl", ShaderType::Vertex };
    Shader fragment_shader = { "assets/shaders/frag.fragment.glsl", ShaderType::Fragment };

    Program program = {
        vertex_shader,
        fragment_shader,
    };

    if(!program.is_valid()) {
        std::cout << program.get_error() << std::endl;
        window.terminate();
        return 1;
    }

    VertexArray vertex_array = {};
    vertex_array.bind();

    DataBuffer data_buffer_position = {
        vertices_triangle,
        sizeof(vertices_triangle)
    };

    DataBuffer data_buffer_color = {
        vertices_color,
        sizeof(vertices_color)
    };

    BufferElement buffer_element_position = {
        BufferDataType::Float3,
        "aPos"
    };

    BufferElement buffer_element_color = {
        BufferDataType::Float4,
        "aCol"
    };

    data_buffer_position.add_element(buffer_element_position);
    data_buffer_color.add_element(buffer_element_color);

    data_buffer_position.configure_by_name(program.get_id());
    data_buffer_color.configure_by_name(program.get_id());

    IndexBuffer index_buffer = {
        index_triangle,
        sizeof(index_triangle)
    };

    while (!window.should_close()) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        program.bind();

        vertex_array.bind();

        glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);

        window.on_update();
    }

    window.terminate();
    return 0;
}