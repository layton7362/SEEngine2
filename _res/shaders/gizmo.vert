#version 450 core

layout(location = 0) in vec3 position;

out vec4 Color;

uniform mat4 transformation;
uniform mat4 view;
uniform mat4 projection;

void main() {
    if(gl_VertexID == 0) {
        Color = vec4(1.0, 0.0, 0.0, 1.0);
    } else if(gl_VertexID == 1) {
        Color = vec4(0, 1, 0, 1);
    } else if(gl_VertexID == 2) {
        Color = vec4(0, 0, 1, 1);
    } else {
        Color = vec4(0.27, 0.27, 0.27, 1.0);
    }
    mat4 matrix = projection * view * transformation;
    gl_Position = matrix * vec4(position, 1);
}