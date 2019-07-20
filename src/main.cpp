#include <iostream>
#include <string>
#include <memory>
#include <cmath>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "core/window.h"
#include "core/keyboard.h"
#include "core/input.h"

#include "graphic/program.h"
#include "graphic/context.h"
#include "graphic/shader.h"
#include "graphic/shader_type.h"
#include "graphic/texture.h"
#include "graphic/camera.h"

#include "primitives/cube.h"

// settings
const short WIDTH = 1600;
const short HEIGHT = 800;
const std::string TITLE = "OPENGL";

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

    std::shared_ptr<Input> input = std::make_shared<Input>();
    window.add_input_controller(input);

    Shader vertex_shader = { "assets/shaders/light.vertex.glsl", ShaderType::Vertex };
    Shader fragment_shader = { "assets/shaders/light.fragment.glsl", ShaderType::Fragment };

    Program program = {
        vertex_shader,
        fragment_shader,
    };

    if(!program.is_valid()) {
        std::cout << program.get_error() << std::endl;
        std::cin.get();
        window.terminate();
        return 1;
    }

    Cube cube = {};

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
        window.on_update_begin();
        float rotate = 0;

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        program.bind();

        float time = float(glfwGetTime());

        if(input->is_key_pressed(Key::Space)) {
            rotate = 1;
        }

        model = glm::rotate(model, time * 0.0001f, glm::vec3(0,1,0));
        program.set_float("time", time);
        program.set_float("uBrightness", static_cast<float>(sin(time)));
        program.set_float("uContrast", static_cast<float>(sin(time)));
        program.set_float("uGrayscale", static_cast<float>(abs(sin(time))));

        program.set_mat4("model", model);

        cube.bind();

        glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);

        window.on_update_end();
    }

    window.terminate();
    return 0;
}