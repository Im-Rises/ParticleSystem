#version 330

in vec2 UV;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main() {
    FragColor = texture(ourTexture, UV);
    //    FragColor = texture(ourTexture, UV) * vec4(ourColor, 1.0);
}
