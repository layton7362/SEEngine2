#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec4 color;
layout(location = 3) in vec2 uv1;

uniform mat4 transformation;

void main() {
    gl_Position = transformation * vec4(position, 1.0);
}