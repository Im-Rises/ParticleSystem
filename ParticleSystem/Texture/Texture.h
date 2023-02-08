#ifndef TEXTURE_H
#define TEXTURE_H

#include <string_view>

class Texture {
private:
    unsigned int textureID;
    int width, height;
    int nrComponents;

public:
    explicit Texture(const std::string_view& texturePath);

    ~Texture();

    void bind() const;

    [[nodiscard]] unsigned int getTexture() const;

public:
    [[nodiscard]] unsigned int getWidth() const;

    [[nodiscard]] unsigned int getHeight() const;
};


#endif // TEXTURE_H
