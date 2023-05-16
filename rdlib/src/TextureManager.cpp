//
// Created by theo on 16/05/23.
//

#include "rdlib/TextureManager.h"

#include <GL/glew.h>
#include <iostream>

#include "stb_image.h"

namespace rdlib {

    std::map<std::string, unsigned int> TextureManager::s_textures = {};

    unsigned int TextureManager::getTexture(std::string path) {
        std::cout << "Requesting " << path << std::endl;
        if (s_textures.find(path) != s_textures.end()) return s_textures[path];

        std::cout << "Texture already loaded!" << std::endl;
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // load and generate the texture
        int width, height, nb_channels;
        unsigned char *data = stbi_load(path.c_str(), &width, &height, &nb_channels, 0);
        std::cout << "Loaded: " << path.c_str() << ", nb_channels: " << nb_channels << std::endl;
        if (data) {
            auto format = nb_channels == 3 ? GL_RGB : GL_RGBA;
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

        s_textures[path] = texture;
        return texture;
    }

} // rdlib