#version 330

in vec2 UV;

out vec4 fragColor;

uniform sampler2D ourTexture;

void main() {
    fragColor = texture(ourTexture, UV);
    if (fragColor.a < 0.1)
    discard;
    fragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
