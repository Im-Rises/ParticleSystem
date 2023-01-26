#version 330 core

layout (location = 0) in vec3 a_vertice;
layout (location = 1) in vec2 a_texCoord;
layout (location = 2) in vec3 a_position;
//layout (location = 3) in vec3 scale;
//layout (location = 4) in vec3 color;

out vec2 v_UV;

uniform mat4 u_view;
uniform mat4 u_projection;

uniform vec3 u_cameraRight;
uniform vec3 u_cameraUp;

void main()
{
	vec2 scale = vec2(0.1f, 0.1f);// Todo: change this to a uniform or most likely a layout
	vec3 billboardPos = a_position
	+ u_cameraRight * a_vertice.x * scale.x
	+ u_cameraUp * a_vertice.y * scale.y;
	gl_Position = u_projection * u_view * vec4(billboardPos, 1.0);
	v_UV = a_texCoord;
}
