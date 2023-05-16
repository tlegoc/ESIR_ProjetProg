//
// Created by theo on 16/05/23.
//

#ifndef ESIR_PROJETPROG_USERINTERFACE_H
#define ESIR_PROJETPROG_USERINTERFACE_H

#include <glm/glm.hpp>

#include <string>
#include <vector>

using namespace glm;

namespace rdlib {

    class UserInterface {

    public:
        static std::string s_vertex_code;

        static std::string s_fragment_code;


        struct RenderableElement {
            vec2 position;
            vec2 size;
            vec3 color;
            std::string image;
            float angle;
        };

        static void init();

        static void renderImage(const std::string& image, vec2 position, vec2 size, vec3 color, float angle = 0);

        // static void renderText(const std::string& text, vec2 position, vec2 size, vec3 color, float angle = 0);

        static void addImage(const std::string& image, vec2 position, vec2 size, vec3 color, float angle = 0);

        static std::vector<RenderableElement> m_renderable_elements;

        static void renderAll();

        static void clear();

        UserInterface() = delete;

        ~UserInterface() = delete;

        UserInterface(const UserInterface&) = delete;

        UserInterface& operator=(const UserInterface&) = delete;

    private:
        static unsigned int s_shader_id;
        static unsigned int s_vao;

    };

} // rdlib

#endif //ESIR_PROJETPROG_USERINTERFACE_H
