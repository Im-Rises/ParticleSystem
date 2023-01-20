#version 330 core

layout (location = 0) in vec3 vertice;
layout (location = 1) in vec3 position;

uniform mat4 view;
uniform mat4 projection;

uniform vec3 cameraRight;
uniform vec3 cameraUp;

void main()
{
    vec2 size = vec2(0.5, 0.5);
    vec3 pos = position
    + cameraRight * vertice.x * size.x
    + cameraUp * vertice.y * size.y;
    gl_Position = projection * view * vec4(pos, 1.0);
}
