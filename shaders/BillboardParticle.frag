#version 330

//in vec3 color;
in vec2 v_UV;

out vec4 o_fragColor;

uniform sampler2D u_ourTexture;

void main() {
	o_fragColor = texture(u_ourTexture, v_UV);
	if (o_fragColor.a < 0.1)
	discard;
	o_fragColor = vec4(1.0, 1.0, 1.0, 1.0);
	//    fragColor = vec4(color, 1.0);
}
