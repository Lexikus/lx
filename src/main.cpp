#include <iostream>
#include <string>

#include <glad/glad.h>

#include "core/graphic/program.h"
#include "core/graphic/context.h"
#include "core/graphic/shader.h"
#include "core/graphic/window.h"
#include "core/graphic/vertex_array.h"

// settings
const short WIDTH = 800;
const short HEIGHT = 800;
const std::string TITLE = "OPENGL";

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

    Shader vertex_shader = { "assets/shaders/vert.vertex.glsl" };
    Shader fragment_shader = { "assets/shaders/frag.fragment.glsl" };

    Program program = {
        vertex_shader,
        fragment_shader,
    };

    if(!program.is_valid()) {
        std::cout << program.get_error() << std::endl;
    }

    VertexArray vertex_array = {};

    while (!window.should_close()) {
        program.bind();

        glClearColor(1.0f, 1.0f, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.on_update();
    }

    window.terminate();
    return 0;
}