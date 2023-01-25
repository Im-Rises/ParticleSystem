#version 330 core

layout(location = 0) in vec3 vertice;
layout(location = 1) in vec2 textureCoord;

out vec2 UV;

uniform mat4 view;
uniform mat4 projection;

uniform vec3 cameraRight;
uniform vec3 cameraUp;

//ToDo: Change to layout variable
uniform vec3 billboardPos;
uniform vec2 billboardSize;


void main()
{
    vec3 pos = billboardPos
    + cameraRight * vertice.x * billboardSize.x
    + cameraUp * vertice.y * billboardSize.y;
    gl_Position = projection * view * vec4(pos, 1.0);
    UV = textureCoord;
}
