#version 330 core



layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in uvec3 color;
layout(location = 3) in vec2 uv1;

uniform float shift_y = 0;
uniform float shift_x = 0;

uniform mat4 transformation;
uniform mat4 view;
uniform mat4 projection;


void main() {
    mat4 matrix = projection * view * transformation;
    // gl_Position = matrix * vec4(position, 1.0);
    gl_Position =  transformation * vec4(position, 1.0);
}