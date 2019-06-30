#version 400 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;

out vec4 vCol;

void main() {
    vCol = aCol;
    // vCol = vec4(1.0, 1.0, 1.0, 1.0);
    gl_Position = vec4(aPos, 1.0);
}