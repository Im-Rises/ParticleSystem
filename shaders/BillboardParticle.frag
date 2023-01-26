#version 330

in vec2 v_UV;
in vec3 v_color;

out vec4 o_fragColor;

uniform sampler2D u_texture;

void main() {
	o_fragColor = texture(u_texture, v_UV);
	if (o_fragColor.a < 0.1)
	discard;
	o_fragColor = vec4(v_color, 1.0);
}
