#pragma once

#include <string>
#include <memory>

#include <GLFW/glfw3.h>

#include "input.h"

class Window {
friend GLFWwindow;
private:
    std::string title_ { };
    int width_ { 0 };
    int height_ { 0 };
    GLFWwindow* window_ { };
    std::shared_ptr<Input> input_controller_ { };
public:
    Window(std::string title, int width, int height);
    ~Window();
    bool init();
    const GLFWwindow *const get_window() const;
    bool should_close() const;
    void set_vsync(bool enable) const;
    void on_update_begin() const;
    void on_update_end() const;
    void terminate() const;
    void add_input_controller(std::shared_ptr<Input> input_controller);
};
