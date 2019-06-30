#include "context.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool Context::init() const {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return false;
    }
    return true;
}
