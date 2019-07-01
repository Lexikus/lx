#version 400 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aUV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 vCol;

void main() {
    vec4 aCol = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    vCol = aCol;
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
}