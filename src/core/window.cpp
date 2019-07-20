#include "window.h"

#include <iostream>
#include <memory>

#include <GLFW/glfw3.h>

#include "keyboard.h"

Window::Window(std::string title, int width, int height):
title_ { title }, width_ { width }, height_ { height } { }

Window::~Window() {
    glfwDestroyWindow(window_);
}

bool Window::init() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ = glfwCreateWindow(width_, height_, title_.c_str(), NULL, NULL);

    if (window_ == nullptr) {
        glfwTerminate();
        return false;
    }

    glfwSetWindowUserPointer(window_, this);
    glfwMakeContextCurrent(window_);

    glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
        glfwSetWindowShouldClose(window, true);
    });

    glfwSetKeyCallback(window_,
        [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            if(key == GLFW_KEY_ESCAPE) {
                glfwSetWindowShouldClose(window, true);
            }

            auto& self { *static_cast<Window*>(glfwGetWindowUserPointer(window)) };
            Key _key { get_key_from_keycode(key) };
            Action _action { get_action_from_actioncode(action) };
            Modifier _modifier { get_modifier_from_modifercode(scancode) };

            self.input_controller_->update(_key, { _key, _action, _modifier });
        });


    return true;
}

const GLFWwindow* const Window::get_window() const{
    return window_;
}

bool Window::should_close() const {
    return glfwWindowShouldClose(window_);
}

void Window::set_vsync(bool enable) const {
  if (enable)
    glfwSwapInterval(1);
  else
    glfwSwapInterval(0);
}

void Window::on_update_begin() const {
    glfwPollEvents();
}

void Window::on_update_end() const {
    glfwSwapBuffers(window_);
}

void Window::terminate() const {
    glfwTerminate();
}

void Window::add_input_controller(std::shared_ptr<Input> input_controller) {
    input_controller_ = input_controller;
}