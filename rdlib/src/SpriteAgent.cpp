//
// Created by theo on 12/05/23.
//

#include "rdlib/SpriteAgent.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "rdlib/Shader.h"
#include "rdlib/Engine.h"
#include "rdlib/TextureManager.h"

#include <GL/glew.h>
#include "glm/gtc/type_ptr.hpp"

namespace rdlib {
    unsigned int SpriteAgent::s_shader_id = 0;

    const std::string SpriteAgent::s_vertex_code = "\n"
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

    const std::string SpriteAgent::s_fragment_code = "#version 330 core\n"
                                               "in vec2 TexCoords;\n"
                                               "out vec4 color;\n"
                                               "\n"
                                               "uniform sampler2D image;\n"
                                               "uniform vec3 spriteColor;\n"
                                               "\n"
                                               "void main()\n"
                                               "{    \n"
                                               "    color = vec4(spriteColor, 1.0) * texture(image, TexCoords * vec2(1.0, -1.0));\n"
                                               "}";

    SpriteAgent::SpriteAgent(const std::string &image, vec3 position, float angle, vec2 size, vec3 color)
            : VisibleAgent() {
        m_image_id = 0;
        m_pos = position;
        m_angle = angle;
        m_size = size;
        m_color = color;

        if (s_shader_id == 0)
            s_shader_id = Shader::LoadShader(s_vertex_code, s_fragment_code);

        // Image
        m_texture = TextureManager::getTexture(image);

        // configure VAO/VBO
        unsigned int VBO;
        float vertices[] = {
                // pos      // tex
                0.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 0.0f,

                0.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 0.0f, 1.0f, 0.0f
        };

        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(m_vao);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *) 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void SpriteAgent::render() {
        // prepare transformations
        glUseProgram(s_shader_id);
        mat4 model = getModelMatrix();
        mat4 camera = Engine::getCameraMatrix();
        // Alpha blend
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glUniformMatrix4fv(glGetUniformLocation(s_shader_id, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(s_shader_id, "camera"), 1, GL_FALSE, glm::value_ptr(camera));
        glUniform3f(glGetUniformLocation(s_shader_id, "spriteColor"), m_color.r, m_color.g, m_color.b);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
        glActiveTexture(0);
    }

    mat4 SpriteAgent::getModelMatrix() {
        // Take into account the position, angle and size

        mat4 model = mat4(1.0f);
        model = glm::translate(model, m_pos);
        model = glm::scale(model, vec3(m_size.x, m_size.y, 1.0f));
        model = glm::rotate(model, m_angle, vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, vec3(-0.5f, -0.5f, 0.0f));

        return model;
    }

    void SpriteAgent::renderAll() {
        for (auto &sprite: Agent::getObjectsOfType<SpriteAgent>()) {
            sprite->render();
        }
    }

    vec3 SpriteAgent::getPos() const {
        return m_pos;
    }

    void SpriteAgent::setPos(const vec3 pos) {
        m_pos = pos;
    }

    float SpriteAgent::getAngle() const {
        return m_angle;
    }

    void SpriteAgent::setAngle(float angle) {
        m_angle = angle;
    }

    vec2 SpriteAgent::getSize() const {
        return m_size;
    }

    void SpriteAgent::setSize(const vec2 size) {
        m_size = size;
    }

    vec3 SpriteAgent::getColor() const {
        return m_color;
    }

    void SpriteAgent::setColor(const vec3 color) {
        m_color = color;
    }
} // rdlib