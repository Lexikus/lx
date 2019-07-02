#include <iostream>
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "../vendor/stb/stb_image.h"

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
const short WIDTH = 1600;
const short HEIGHT = 800;
const std::string TITLE = "OPENGL";

glm::vec3 vertices_cube[] = {
    //front
    { -1,-1,1 },
    { 1,-1,1 },
    { 1,1,1 },
    { -1,1,1 },
    //back
    { -1,-1,-1 },
    { 1,-1,-1 },
    { 1,1,-1 },
    { -1,1,-1 },
    //right
    { 1,-1,1 },
    { 1,-1,-1 },
    { 1,1,-1 },
    { 1,1,1 },
    //left
    { -1,-1,1 },
    { -1,-1,-1 },
    { -1,1,-1 },
    { -1,1,1 },
    //top
    { -1,1,1 },
    { 1,1,1 },
    { 1,1,-1 },
    { -1,1,-1 },
    //bottom
    { -1,-1,1 },
    { 1,-1,1 },
    { 1,-1,-1 },
    { -1,-1,-1 },
};

glm::vec4 colors_cube[] = {
    //front
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    //back
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    //right
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    //left
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    //top
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    //bottom
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
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

glm::vec2 uvs_cube[] = {
    { 0.0f, 0.0f },
    { 1.0f, 0.0f },
    { 1.0f, 1.0f },
    { 0.0f, 1.0f },

    { 0.0f, 0.0f },
    { 1.0f, 0.0f },
    { 1.0f, 1.0f },
    { 0.0f, 1.0f },

    { 0.0f, 0.0f },
    { 1.0f, 0.0f },
    { 1.0f, 1.0f },
    { 0.0f, 1.0f },

    { 0.0f, 0.0f },
    { 1.0f, 0.0f },
    { 1.0f, 1.0f },
    { 0.0f, 1.0f },

    { 0.0f, 0.0f },
    { 1.0f, 0.0f },
    { 1.0f, 1.0f },
    { 0.0f, 1.0f },

    { 0.0f, 0.0f },
    { 1.0f, 0.0f },
    { 1.0f, 1.0f },
    { 0.0f, 1.0f },
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

    Shader vertex_shader = { "assets/shaders/temp.vertex.glsl", ShaderType::Vertex };
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
        uvs_cube,
        sizeof(uvs_cube)
    };

    DataBuffer data_buffer_color = {
        colors_cube,
        sizeof(colors_cube)
    };

    BufferElement buffer_element_position = {
        BufferDataType::Float3,
        "aPos"
    };

    BufferElement buffer_element_uv = {
        BufferDataType::Float2,
        "aUV"
    };

    BufferElement buffer_element_color = {
        BufferDataType::Float4,
        "aCol"
    };

    data_buffer_position.add_element(buffer_element_position);
    data_buffer_uv.add_element(buffer_element_uv);
    data_buffer_color.add_element(buffer_element_color);

    data_buffer_position.configure_by_name(program.get_id());
    data_buffer_uv.configure_by_name(program.get_id());
    data_buffer_color.configure_by_name(program.get_id());

    IndexBuffer index_buffer = {
        indices_cube,
        sizeof(indices_cube)
    };

    // camera, view and projection
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    // model = glm::translate(model, glm::vec3(0, 0, 6));
    // model = glm::rotate(model, 45.0f, glm::vec3(0,1,0));
    // model = glm::scale(model, glm::vec3(1, 1, 1));
    // view = glm::translate(view, glm::vec3(0, 0, -10));
    // projection = glm::perspective<float>(45.0f, (float)WIDTH/HEIGHT, 0.1f, 1000.0f);
    // projection = glm::ortho(-(float)WIDTH / 2, (float)WIDTH / 2, -(float)HEIGHT / 2, (float)HEIGHT / 2, 0.1f, 1000.0f);

    glEnable(GL_DEPTH_TEST);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("assets/textures/crate.jpg", &width, &height, &nrChannels, 0);

    unsigned int texture_id = 0;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Texture settings
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    while (!window.should_close()) {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        program.bind();

        program.set_float("time", float(glfwGetTime()));
        // program.set_mat4("model", model);
        // program.set_mat4("view", view);
        // program.set_mat4("projection", projection);

        vertex_array.bind();

        glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);

        window.on_update();
    }

    window.terminate();
    stbi_image_free(data);
    return 0;
}