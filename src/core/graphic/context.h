#pragma once

#include <string>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Context
{
private:
    // std::unique_ptr<GLFWwindow> _window;

public:
    bool Init(std::string, int width, int height);
    GLFWwindow *const getWindow();
};