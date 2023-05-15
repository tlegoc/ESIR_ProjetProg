//
// Created by theo on 12/05/23.
//

#ifndef ESIR_PROJETPROG_SPRITE_H
#define ESIR_PROJETPROG_SPRITE_H

#include "VisibleAgent.h"

#include <glm/glm.hpp>
#include <string>

using namespace glm;

namespace rdlib {

    class Sprite : public VisibleAgent {
    public:
        static std::string s_vertex_code;
        static std::string s_fragment_code;


        Sprite(std::string image, vec3 position = vec3(0, 0, 0), float angle = 0.0f, float size = 1.0f, vec3 color = vec3(1.0f, 1.0f, 1.0f));
        void render() override;
        void update() override;
        mat4 getModelMatrix();

        static void renderAll();

    private:
        unsigned int m_image_id;
        unsigned int m_shader_id;
        unsigned int m_vao;
        unsigned int m_texture;
        unsigned int m_texture_height;
        unsigned int m_texture_width;

        vec3 m_pos;
        float m_angle;
        float m_size;
        vec3 m_color;
    };

} // rdlib

#endif //ESIR_PROJETPROG_SPRITE_H
