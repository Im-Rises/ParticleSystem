#version 330

in vec2 UV;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main() {
    FragColor = texture(ourTexture, UV);
    //    FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
