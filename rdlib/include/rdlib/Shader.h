//
// Created by theo on 15/05/23.
//

#ifndef ESIR_PROJETPROG_SHADER_H
#define ESIR_PROJETPROG_SHADER_H

#include <string>

namespace rdlib::Shader {
    unsigned int LoadShader(const std::string &vertex_path, std::string fragment_path);

} // rdlib

#endif //ESIR_PROJETPROG_SHADER_H
