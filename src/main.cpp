#include <iostream>
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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

glm::vec3 vertices_cube[] = {
    //front
    { -0.5f,-0.5f,0.5f },
    { 0.5f,-0.5f,0.5f },
    { 0.5f,0.5f,0.5f },
    { -0.5f,0.5f,0.5f },
    //back
    { -0.5f,-0.5f,-0.5f },
    { 0.5f,-0.5f,-0.5f },
    { 0.5f,0.5f,-0.5f },
    { -0.5f,0.5f,-0.5f },
    //right
    { 0.5f,-0.5f,0.5f },
    { 0.5f,-0.5f,-0.5f },
    { 0.5f,0.5f,-0.5f },
    { 0.5f,0.5f,0.5f },
    //left
    { -0.5f,-0.5f,0.5f },
    { -0.5f,-0.5f,-0.5f },
    { -0.5f,0.5f,-0.5f },
    { -0.5f,0.5f,0.5f },
    //top
    { -0.5f,0.5f,0.5f },
    { 0.5f,0.5f,0.5f },
    { 0.5f,0.5f,-0.5f },
    { -0.5f,0.5f,-0.5f },
    //bottom
    { -0.5f,-0.5f,0.5f },
    { 0.5f,-0.5f,0.5f },
    { 0.5f,-0.5f,-0.5f },
    { -0.5f,-0.5f,-0.5f },
};

glm::ivec3 indices_cube[] = {
    { 0,1,2 },
    { 0,2,3 },

    { 8,9,10 },
    { 8,10,11 },

    { 5,4,7 },
    { 5,7,6 },

    { 13,12,15 },
    { 13,15,14 },

    { 16,17,18 },
    { 16,18,19 },

    { 21,20,23 },
    { 21,23,22 }
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
        vertices_cube,
        sizeof(vertices_cube)
    };

    DataBuffer data_buffer_uv = {
        indices_cube,
        sizeof(indices_cube)
    };

    BufferElement buffer_element_position = {
        BufferDataType::Float3,
        "aPos"
    };

    BufferElement buffer_element_color = {
        BufferDataType::Float3,
        "aUV"
    };

    data_buffer_position.add_element(buffer_element_position);
    data_buffer_uv.add_element(buffer_element_color);

    data_buffer_position.configure_by_name(program.get_id());
    data_buffer_uv.configure_by_name(program.get_id());

    IndexBuffer index_buffer = {
        indices_cube,
        sizeof(indices_cube)
    };

    // camera, view and projection
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(0, 0, 3));
    model = glm::scale(model, glm::vec3(100, 100, 100));
    view = glm::translate(view, glm::vec3(0, 0, -10));
    projection = glm::ortho(-(float)WIDTH / 2, (float)WIDTH / 2, -(float)HEIGHT / 2, (float)HEIGHT / 2, 0.1f, 100.0f);

    while (!window.should_close()) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        program.bind();

        program.set_mat4("model", model);
        program.set_mat4("view", view);
        program.set_mat4("projection", projection);

        vertex_array.bind();

        glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);

        window.on_update();
    }

    window.terminate();
    return 0;
}