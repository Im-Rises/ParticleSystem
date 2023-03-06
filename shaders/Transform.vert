#version 330 core
layout (location = 0) in vec3 a_Pos;

uniform mat4 u_mvp;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_mvp * u_model * vec4(a_Pos, 1.0f);
}
