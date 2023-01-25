#version 330 core

layout (location = 0) in vec3 vertice;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 position;
//layout (location = 3) in vec3 scale;

out vec2 UV;

uniform mat4 view;
uniform mat4 projection;

uniform vec3 cameraRight;
uniform vec3 cameraUp;

void main()
{
    vec2 scale = vec2(0.1f, 0.1f);// Todo: change this to a uniform or most likely a layout
    vec3 billboardPos = position
    + cameraRight * vertice.x * scale.x
    + cameraUp * vertice.y * scale.y;
    gl_Position = projection * view * vec4(billboardPos, 1.0);
    UV = texCoord;
}
