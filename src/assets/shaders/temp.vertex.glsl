#version 400 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
layout (location = 2) in vec2 aUV;

uniform float time;

out vec4 vCol;
out vec2 vUV;

void main() {
    float a = 1.0f;
    float f = 1.0f;
    float s = a * sin(f * time);
    float k = -10.0f;

    vCol = aCol;
    vUV = aUV * k;

    gl_Position = vec4(aPos, 1.0f);
}