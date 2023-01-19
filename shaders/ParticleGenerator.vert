#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aOffset;
//layout (location = 2) in vec4 xyzs;// Position of the center of the particule and size of the square

uniform mat4 view;
uniform mat4 projection;
//uniform vec3 cameraRight;
//uniform vec3 cameraUp;

void main()
{
    // Billboard the particule
    //    float particleSize = 0.1;
    //    vec3 particleCenter = aPos.xyz;
    //
    //    vec3 vertexPosition = particleCenter +
    //    aPos.x * particleSize * cameraRight +
    //    aPos.y * particleSize * cameraUp;
    //
    //    // Output position of the vertex
    //    gl_Position = projection * view * vec4(vertexPosition+aOffset, 1.0f);


    // Simple shader
    gl_Position = projection * view * vec4(aPos + aOffset, 1.0);
}
