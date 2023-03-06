#version 330 core

in vec2 v_UV;
in vec4 v_color;

out vec4 o_fragColor;

uniform sampler2D u_texture;

void main() {
	o_fragColor = texture(u_texture, v_UV);
	if (o_fragColor.a < 0.1)
	discard;
	o_fragColor = v_color;
}
