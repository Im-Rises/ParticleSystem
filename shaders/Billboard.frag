#version 330

in vec2 UV;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main() {
    //    FragColor = vec4(0.0, 0.0, 0.0, 1.0);
    FragColor = texture(ourTexture, UV);
}
