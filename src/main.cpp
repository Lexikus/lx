#include <iostream>
#include <string>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "core/window.h"

#include "graphic/program.h"
#include "graphic/context.h"
#include "graphic/shader.h"
#include "graphic/shader_type.h"
#include "graphic/vertex_array.h"
#include "graphic/buffer_data_type.h"
#include "graphic/buffer_element.h"
#include "graphic/data_buffer.h"
#include "graphic/index_buffer.h"
#include "graphic/texture.h"
#include "graphic/camera.h"

// settings
const short WIDTH = 1600;
const short HEIGHT = 800;
const std::string TITLE = "OPENGL";

glm::vec3 vertices_cube[] = {
    { -1.0f, -1.0f, 1.0f },
    {  1.0f, -1.0f, 1.0f },
    {  1.0f,  1.0f, 1.0f },
    { -1.0f,  1.0f, 1.0f },

    { -1.0f, -1.0f, -1.0f },
    {  1.0f, -1.0f, -1.0f },
    {  1.0f,  1.0f, -1.0f },
    { -1.0f,  1.0f, -1.0f },

    {  1.0f, -1.0f,  1.0f },
    {  1.0f, -1.0f, -1.0f },
    {  1.0f,  1.0f, -1.0f },
    {  1.0f,  1.0f,  1.0f },

    { -1.0f, -1.0f,  1.0f },
    { -1.0f, -1.0f, -1.0f },
    { -1.0f,  1.0f, -1.0f },
    { -1.0f,  1.0f,  1.0f },

    { -1.0f,  1.0f,  1.0f },
    {  1.0f,  1.0f,  1.0f },
    {  1.0f,  1.0f, -1.0f },
    { -1.0f,  1.0f, -1.0f },

    { -1.0f, -1.0f,  1.0f },
    {  1.0f, -1.0f,  1.0f },
    {  1.0f, -1.0f, -1.0f },
    { -1.0f, -1.0f, -1.0f },
};

glm::ivec3 indices_cube[] = {
    { 0, 1, 2 },
    { 0, 2, 3 },
    { 8, 9, 10 },
    { 8, 10, 11 },
    { 5, 4, 7 },
    { 5, 7, 6 },
    { 13, 12, 15 },
    { 13, 15, 14 },
    { 16, 17, 18 },
    { 16, 18, 19 },
    { 21, 20, 23 },
    { 21, 23, 22},
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

glm::vec4 color_cube[] = {
    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },

    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },

    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },

    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },

    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },

    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
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

    Shader vertex_shader = { "assets/shaders/color_manipulation.vertex.glsl", ShaderType::Vertex };
    Shader fragment_shader = { "assets/shaders/color_manipulation.fragment.glsl", ShaderType::Fragment };

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
        color_cube,
        sizeof(color_cube)
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
    data_buffer_position.configure_by_name(program.get_id());

    data_buffer_uv.add_element(buffer_element_uv);
    data_buffer_uv.configure_by_name(program.get_id());

    data_buffer_color.add_element(buffer_element_color);
    data_buffer_color.configure_by_name(program.get_id());

    IndexBuffer index_buffer = {
        indices_cube,
        sizeof(indices_cube)
    };

    glm::mat4 model = glm::mat4(1.0f);

    Camera camera;
    camera.create_perspective(45.0f, (float)WIDTH/HEIGHT, 0.1f, 1000.0f);

    program.bind();
    program.set_mat4("view", camera.get_view());
    program.set_mat4("projection", camera.get_projection());

    model = glm::translate(model, glm::vec3(0, 0, -5));
    model = glm::rotate(model, 45.0f, glm::vec3(0,1,0));
    model = glm::scale(model, glm::vec3(1, 1, 1));

    Texture texture = {
        "assets/textures/crate.jpg"
    };
    texture.bind();

    // Settings
    glEnable(GL_DEPTH_TEST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    while (!window.should_close()) {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        program.bind();

        float time = float(glfwGetTime());

        model = glm::rotate(model, 0.0001f, glm::vec3(0,1,0));
        program.set_float("time", time);
        program.set_float("uBrightness", sin(time));
        program.set_float("uContrast", sin(time));
        program.set_float("uGrayscale", fabsf32(sin(time)));

        program.set_mat4("model", model);

        vertex_array.bind();

        glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);

        window.on_update();
    }

    window.terminate();

    return 0;
}