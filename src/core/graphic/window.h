#pragma once

#include <string>
#include <memory>

#include <GLFW/glfw3.h>

class Window {
private:
    std::string title_;
    int width_ = 0;
    int height_ = 0;
    GLFWwindow* window_;
public:
    Window(std::string title, int width, int height);
    ~Window();
    bool init();
    const GLFWwindow *const get_window() const;
    bool should_close() const;
    void set_vsync(bool enable) const;
    void on_update() const;
    void terminate() const;
};
