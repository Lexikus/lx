#pragma once

#include <string>
#include <memory>

#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* window_;
public:
    ~Window();
    bool init(std::string, int width, int height);
    const GLFWwindow *const get_window();
    bool should_close();
    void set_vsync(bool enable);
    void on_update();
    void terminate();
};