#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 aOffset;

uniform mat4 view;
uniform mat4 projection;

out vec3 fColor;

void main()
{
    fColor = aColor;
    gl_Position = projection * view * model * vec4(aPos + aOffset, 1.0);
}
