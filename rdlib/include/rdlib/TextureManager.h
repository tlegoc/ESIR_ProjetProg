//
// Created by theo on 16/05/23.
//

#ifndef ESIR_PROJETPROG_TEXTUREMANAGER_H
#define ESIR_PROJETPROG_TEXTUREMANAGER_H

#include <iostream>
#include <string>
#include <map>

namespace rdlib {

    class TextureManager {
    public:
        TextureManager() = delete;

        TextureManager(const TextureManager &) = delete;

        TextureManager &operator=(const TextureManager &) = delete;

        ~TextureManager() = delete;

        static unsigned int getTexture(std::string path);
    private:
        static TextureManager* s_texture_manager;
        static std::map<std::string, unsigned int> s_textures;
    };

} // rdlib

#endif //ESIR_PROJETPROG_TEXTUREMANAGER_H
