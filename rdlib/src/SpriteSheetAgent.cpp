//
// Created by theo on 16/05/23.
//

#include "rdlib/SpriteSheetAgent.h"

#include "rdlib/Engine.h"
#include "rdlib/Shader.h"
#include "rdlib/Time.h"

#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include "glm/gtc/type_ptr.hpp"

namespace rdlib {
    unsigned int SpriteSheetAgent::s_shader_id = 0;

    const std::string SpriteSheetAgent::s_vertex_code = "\n"
                                                   "#version 330 core\n"
                                                   "layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>\n"
                                                   "\n"
                                                   "out vec2 TexCoords;\n"
                                                   "\n"
                                                   "uniform mat4 model;\n"
                                                   "uniform mat4 camera;\n"
                                                   "\n"
                                                   "void main()\n"
                                                   "{\n"
                                                   "    TexCoords = vertex.zw;\n"
                                                   "    gl_Position = camera * model * vec4(vertex.xy, 0.0, 1.0);\n"
                                                   "}";

    const std::string SpriteSheetAgent::s_fragment_code = "#version 330 core\n"
                                                          "in vec2 TexCoords;\n"
                                                          "out vec4 color;\n"
                                                          "\n"
                                                          "uniform sampler2D image;\n"
                                                          "uniform vec3 spriteColor;\n"
                                                          "uniform uint currentTile;\n"
                                                          "uniform uvec2 tileSize;\n"
                                                          "\n"
                                                          "void main()\n"
                                                          "{    \n"
                                                          "    ivec2 textureSize = textureSize(image, 0);\n"
                                                          "\n"
                                                          "    float w = textureSize.x;\n"
                                                          "    float h = textureSize.y;\n"
                                                          "\n"
                                                          "    // Normalize sprite size (0.0-1.0)\n"
                                                          "    float dx = tileSize.x / w;\n"
                                                          "    float dy = tileSize.y / h;\n"
                                                          "\n"
                                                          "    // Figure out number of tile cols of sprite sheet\n"
                                                          "    float cols = w / tileSize.x;\n"
                                                          "\n"
                                                          "    // From linear index to row/col pair\n"
                                                          "    float col = mod(currentTile, cols);\n"
                                                          "    float row = floor(currentTile / cols);\n"
                                                          "    // Finally to UV texture coordinates\n"
                                                          "    vec2 uv = vec2(dx * TexCoords.x + col * dx, 1.0 - dy - row * dy + dy * TexCoords.y);\n"
                                                          "\n"
                                                          "    color = vec4(spriteColor, 1.0) * texture(image, uv * vec2(1.0, -1.0));\n"
                                                          "}";

    SpriteSheetAgent::SpriteSheetAgent(const std::string& image, uvec2 tile_size, float frametime, vec3 position, float angle, vec2 size, vec3 color) : SpriteAgent(image, position, angle, size, color) {
        m_tile_size = tile_size;
        m_frametime = frametime;
        m_current_anim_pos = 0;
        m_loop = false;
        m_anim = {0};

        if (s_shader_id == 0)
            s_shader_id = Shader::LoadShader(s_vertex_code, s_fragment_code);
    }

    void SpriteSheetAgent::render() {
        // prepare transformations
        glUseProgram(s_shader_id);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        mat4 model = getModelMatrix();
        mat4 camera = Engine::getCameraMatrix();

        glUniformMatrix4fv(glGetUniformLocation(s_shader_id, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(s_shader_id, "camera"), 1, GL_FALSE, glm::value_ptr(camera));
        glUniform3f(glGetUniformLocation(s_shader_id, "spriteColor"), m_color.r, m_color.g, m_color.b);
        glUniform1ui(glGetUniformLocation(s_shader_id, "currentTile"), m_anim[(int) (m_current_anim_pos / m_frametime)]);
        glUniform2ui(glGetUniformLocation(s_shader_id, "tileSize"), m_tile_size.x, m_tile_size.y);


        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
        glActiveTexture(0);
        m_current_anim_pos += Time::getDelta();
        m_current_anim_pos = glm::mod(m_current_anim_pos, m_frametime*m_anim.size());
        std::cout << (int) (m_current_anim_pos / m_frametime) << std::endl;
    }

    void SpriteSheetAgent::playAnimation(std::vector<unsigned int> anim, bool loop) {
        m_anim = anim;
    }

} // rdlib