#include "texture.h"

#include <glad/glad.h>

#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "../../vendor/stb/stb_image.h"

Texture::Texture(std::string path) {
    int width { 0 };
    int height { 0 };
    int nrChannels { 0 };

    unsigned char *pixel_data { stbi_load(path.c_str(), &width, &height, &nrChannels, 0) };

    glGenTextures(1, &id_);
    glBindTexture(GL_TEXTURE_2D, id_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel_data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(pixel_data);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, id_);
}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}