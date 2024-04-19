#version 330 core

layout(location = 0) in vec3 aPos;

uniform float shift_y = 0;
uniform float shift_x = 0;

void main() {
    gl_Position = vec4(aPos.x + shift_x, aPos.y + shift_y, aPos.z, 1.0);
}