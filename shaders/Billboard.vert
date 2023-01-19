#version 330 core

layout(location = 0) in vec3 vertice;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 CameraRight_worldspace;
uniform vec3 CameraUp_worldspace;
uniform vec3 BillboardPos;
uniform vec2 BillboardSize;

void main()
{
    vec3 particleCenter_wordspace = BillboardPos;

    vec3 vertexPosition_worldspace =
    particleCenter_wordspace
    + CameraRight_worldspace * vertice.x * BillboardSize.x
    + CameraUp_worldspace * vertice.y * BillboardSize.y;

    gl_Position = view * projection * vec4(vertexPosition_worldspace, 1.0f);

    gl_Position = projection * view * model * vec4(vertice, 1.0f);
}
