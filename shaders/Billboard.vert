#version 330 core

layout(location = 0) in vec3 vertice;
layout(location = 1) in vec2 textureCoord;

uniform mat4 view;
uniform mat4 projection;

uniform vec3 CameraRight_worldspace;
uniform vec3 CameraUp_worldspace;

uniform vec3 BillboardPos;
uniform vec2 BillboardSize;

out vec2 UV;

void main()
{
    vec3 pos = BillboardPos
    + CameraRight_worldspace * vertice.x * BillboardSize.x
    + CameraUp_worldspace * vertice.y * BillboardSize.y;
    gl_Position = projection * view * vec4(pos, 1.0);
    UV = textureCoord;
}
