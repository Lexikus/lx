#include "context.h"

#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool Context::Init(std::string title, int width, int height) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    // _window = std::make_unique<GLFWwindow>(window);

    if (window == nullptr) {
      std::cout << "FAILED to create a window" << std::endl;
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    return true;
}

GLFWwindow* const Context::getWindow(){
    return nullptr;
}