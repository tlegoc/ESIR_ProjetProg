//
// Created by theo on 16/05/23.
//

#ifndef ESIR_PROJETPROG_SPRITESHEETAGENT_H
#define ESIR_PROJETPROG_SPRITESHEETAGENT_H

#include <rdlib/SpriteAgent.h>

namespace rdlib {

    class SpriteSheetAgent : public SpriteAgent {

    public:
        const static std::string s_vertex_code;
        const static std::string s_fragment_code;

        explicit SpriteSheetAgent(const std::string& image, uvec2 tile_size, float frametime, vec3 position = vec3(0, 0, 0), float angle = 0, vec2 size = vec2(1,1), vec3 color = vec3(1, 1, 1));

        void render() override;
        void playAnimation(std::vector<unsigned int> anim, bool loop = true);
        bool animationFinished();

    private:
        static unsigned int s_shader_id;

        uvec2 m_tile_size{};
        float m_frametime;
        float m_current_anim_pos;
        bool m_loop;
        std::vector<unsigned int> m_anim;
    };

} // rdlib

#endif //ESIR_PROJETPROG_SPRITESHEETAGENT_H
