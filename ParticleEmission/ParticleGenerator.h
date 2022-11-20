#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include <glad/glad.h>

#define MAX_PARTICLES 10000

class ParticleGenerator {
private:
    static inline constexpr GLfloat g_vertex_buffer_data[] = {
        -0.5F,
        -0.5F,
        0.0F,
        0.5F,
        -0.5F,
        0.0F,
        -0.5F,
        0.5F,
        0.0F,
        0.5F,
        0.5F,
        0.0F,
    };

    GLuint billboard_vertex_buffer;
    GLuint particles_position_buffer;
    GLuint particles_color_buffer;

    GLuint particles_count = 0;

    GLfloat g_particle_position_size_data[MAX_PARTICLES * 4];
    GLfloat g_particle_color_data[MAX_PARTICLES * 4];

public:
    ParticleGenerator();
    ~ParticleGenerator();

    void update();

    void render();
};



#endif // PARTICLEGENERATOR_H
