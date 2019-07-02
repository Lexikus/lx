#version 400 core

in vec4 vCol;
in vec2 vUV;

out vec4 fragColor;

uniform sampler2D texture;

void main()
{
    vec3 color = texture(texture, vUV).rgb;
    // fragColor = vCol;
    fragColor = vec4(color, 1) * vCol;
}