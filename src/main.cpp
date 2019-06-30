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

// settings
const short WIDTH = 800;
const short HEIGHT = 800;
const std::string TITLE = "OPENGL";

float vertices_triangle[] = {
     1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
};

int index_triangle[] = {
    0, 1, 2
};

int main() {
    Window window = {};
    if(!window.init(TITLE, WIDTH, HEIGHT)) {
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

    DataBuffer data_buffer = {
        vertices_triangle,
        sizeof(vertices_triangle)
    };

    BufferElement buffer_element_position = {
        BufferDataType::Float3,
        "aPos"
    };

    BufferElement buffer_element_color = {
        BufferDataType::Float4,
        "aCol"
    };

    data_buffer.add_layout(buffer_element_position);
    data_buffer.add_layout(buffer_element_color);

    data_buffer.configure();

    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_triangle), index_triangle, GL_STATIC_DRAW);

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