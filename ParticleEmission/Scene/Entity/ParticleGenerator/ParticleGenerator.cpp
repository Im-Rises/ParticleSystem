/*
#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator() : Entity(
        "ParticleGeneratorVertexShader.vert",
        "ParticleGeneratorFragmentShader.frag") {
    init();
}

void ParticleGenerator::init() {
    glGenBuffers(1, &billboard_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

// The VBO containing the positions and sizes of the particles
    GLuint particles_position_buffer;
    glGenBuffers(1, &particles_position_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
// Initialize with empty (NULL) buffer : it will be updated later, each frame.
    glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);

// The VBO containing the colors of the particles
    GLuint particles_color_buffer;
    glGenBuffers(1, &particles_color_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
// Initialize with empty (NULL) buffer : it will be updated later, each frame.
    glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW);
}

ParticleGenerator::~ParticleGenerator() {
//    glDeleteBuffers(1, &particlesColorBuffer);
//    glDeleteBuffers(1, &particlesPositionBuffer);
//    glDeleteBuffers(1, &billboardVertexBuffer);
}

void ParticleGenerator::update(float deltaTime) {
    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLfloat), NULL,
                 GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf. See above link for details.
    glBufferSubData(GL_ARRAY_BUFFER, 0, ParticlesCount * sizeof(GLfloat) * 4, g_particule_position_size_data);

    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glBufferData(GL_ARRAY_BUFFER, MaxParticles * 4 * sizeof(GLubyte), NULL,
                 GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf. See above link for details.
    glBufferSubData(GL_ARRAY_BUFFER, 0, ParticlesCount * sizeof(GLubyte) * 4, g_particule_color_data);
}

void ParticleGenerator::render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {
// 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
    glVertexAttribPointer(
            0, // attribute. No particular reason for 0, but must match the layout in the shader.
            3, // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0, // stride
            (void *) 0 // array buffer offset
    );

// 2nd attribute buffer : positions of particles' centers
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    glVertexAttribPointer(
            1, // attribute. No particular reason for 1, but must match the layout in the shader.
            4, // size : x + y + z + size => 4
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0, // stride
            (void *) 0 // array buffer offset
    );

// 3rd attribute buffer : particles' colors
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glVertexAttribPointer(
            2, // attribute. No particular reason for 1, but must match the layout in the shader.
            4, // size : r + g + b + a => 4
            GL_UNSIGNED_BYTE, // type
            GL_TRUE, // normalized? *** YES, this means that the unsigned char[4] will be accessible with a vec4 (floats) in the shader ***
            0, // stride
            (void *) 0 // array buffer offset
    );
}

int ParticleGenerator::findUnusedParticle() {

    return 0;
}

int ParticleGenerator::FindUnusedParticle() {
    for (int i = LastUsedParticle; i < MaxParticles; i++) {
        if (ParticlesContainer[i].life < 0) {
            LastUsedParticle = i;
            return i;
        }
    }

    for (int i = 0; i < LastUsedParticle; i++) {
        if (ParticlesContainer[i].life < 0) {
            LastUsedParticle = i;
            return i;
        }
    }

    return 0; // All particles are taken, override the first one
}

void ParticleGenerator::SortParticles() {
    std::sort(&ParticlesContainer[0], &ParticlesContainer[MaxParticles]);
}


*/
