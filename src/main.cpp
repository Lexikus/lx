#include <iostream>
#include <string>
#include <glad/glad.h>

#include "core/graphic/window.h"
#include "core/graphic/context.h"
#include "core/graphic/shader.h"

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

    Shader shader = { "assets/shaders/vert.vertex.glsl" };
    if(!shader.is_valid()) {
        std::cout << shader.get_error() << std::endl;
    }


    while (!window.should_close()) {

        glClearColor(1.0f, 1.0f, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.on_update();
    }

    window.terminate();
    return 0;
}