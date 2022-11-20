#ifndef SHADER_H
#define SHADER_H


class Shader {
private:
    unsigned int ID;

public:
    Shader(const char *vertexPath, const char *fragmentPath);

    ~Shader();

    void use();
};


#endif //SHADER_H
