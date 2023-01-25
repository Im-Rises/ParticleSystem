#ifndef TEXTURE_H
#define TEXTURE_H

#include <string_view>

class Texture {
private:
    unsigned int texture;
    unsigned int width, height;

public:
    explicit Texture(const std::string_view &texturePath);

    ~Texture();

    unsigned int getTexture() const;

public:
    unsigned int getWidth() const;

    unsigned int getHeight() const;

};


#endif //TEXTURE_H
