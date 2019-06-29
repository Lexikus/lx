#include "window.h"

#include <iostream>
#include <memory>

#include <GLFW/glfw3.h>

Window::~Window() {
    glfwDestroyWindow(window_);
}

bool Window::init(std::string title, int width, int height) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);;

    if (window_ == nullptr) {
        std::cout << "FAILED to create a window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window_);

    // TODO: make this somehow seperate like a EventHandler
    // callback for closing window
    // callback for keys
    // basically, those below should not be here... they should get
    // an instance of the window to handle that stuff
    glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
        glfwSetWindowShouldClose(window, true);
    });

    glfwSetKeyCallback(window_,
        [](GLFWwindow* window, int key, int scancode,int action, int mods) {

        if(key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, true);
        }
    });

    return true;
}

const GLFWwindow* const Window::get_window(){
    return window_;
}

bool Window::should_close(){
    return glfwWindowShouldClose(window_);
}

void Window::set_vsync(bool enable) {
  if (enable)
    glfwSwapInterval(1);
  else
    glfwSwapInterval(0);
}

void Window::on_update() {
    glfwSwapBuffers(window_);
    glfwPollEvents();
}

void Window::terminate() {
    glfwTerminate();
}