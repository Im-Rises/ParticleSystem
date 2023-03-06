#version 330 core

layout(location = 0) in vec3 a_vertice;
layout(location = 1) in vec2 a_textureCoord;

out vec2 v_UV;

uniform mat4 u_mvp;

uniform vec3 u_cameraRight;
uniform vec3 u_cameraUp;

//ToDo: Change to layout variable
uniform vec3 u_billboardPos;
uniform vec2 u_billboardScale;


void main()
{
	vec3 pos = u_billboardPos
	+ u_cameraRight * a_vertice.x * u_billboardScale.x
	+ u_cameraUp * a_vertice.y * u_billboardScale.y;
	gl_Position = u_mvp * vec4(pos, 1.0);
	v_UV = a_textureCoord;
}
