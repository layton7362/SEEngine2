#version 450 core

in vec4 Color;

out vec4 FragColor;

void main() {
    // vec4 nC = clamp(Color,vec4(0), vec4(1));
    FragColor = vec4(Color);
    
    // FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}