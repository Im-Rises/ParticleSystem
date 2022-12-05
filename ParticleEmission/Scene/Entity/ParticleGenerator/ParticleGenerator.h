#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include "../Entity.h"
#include <glad/include/glad/glad.h>
#include <glm/glm.hpp>


class ParticleGenerator : public Entity {
private:
/*    // OpenGL buffer data
    static inline constexpr GLfloat g_vertex_buffer_data[] = {
            -0.5F,
*/

public:
    ParticleGenerator();

    void init();

    ~ParticleGenerator();

    void destroy();

    void update(float deltaTime) override;

    void render(glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) override;

};

#endif // PARTICLEGENERATOR_H
