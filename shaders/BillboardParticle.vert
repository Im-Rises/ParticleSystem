#version 330 core

layout (location = 0) in vec3 a_vertice;
layout (location = 1) in vec3 a_position;
layout (location = 2) in vec2 a_scale;
layout (location = 3) in vec3 a_color;

out vec2 v_UV;
out vec3 v_color;

uniform mat4 u_view;
uniform mat4 u_projection;

uniform vec3 u_cameraRight;
uniform vec3 u_cameraUp;

void main()
{
	vec3 billboardPos = a_position
	+ u_cameraRight * a_vertice.x * a_scale.x
	+ u_cameraUp * a_vertice.y * a_scale.y;
	gl_Position = u_projection * u_view * vec4(billboardPos, 1.0);
	v_UV = a_vertice.xy + vec2(0.5, 0.5);
	v_color = a_color;
}
