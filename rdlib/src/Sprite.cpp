//
// Created by theo on 12/05/23.
//

#include "rdlib/Sprite.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "rdlib/Shader.h"

#include <GL/glew.h>
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace rdlib {
    std::string Sprite::s_vertex_code = "\n"
                                        "#version 330 core\n"
                                        "layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>\n"
                                        "\n"
                                        "out vec2 TexCoords;\n"
                                        "\n"
                                        "uniform mat4 model;\n"
                                        "\n"
                                        "void main()\n"
                                        "{\n"
                                        "    TexCoords = vertex.zw;\n"
                                        "    gl_Position = model * vec4(vertex.xy, 0.0, 1.0);\n"
                                        "}";

    std::string Sprite::s_fragment_code = "#version 330 core\n"
                                          "in vec2 TexCoords;\n"
                                          "out vec4 color;\n"
                                          "\n"
                                          "uniform sampler2D image;\n"
                                          "uniform vec3 spriteColor;\n"
                                          "\n"
                                          "void main()\n"
                                          "{    \n"
                                          "    color = vec4(spriteColor, 1.0) * texture(image, TexCoords);\n"
                                          "}";

    Sprite::Sprite(std::string image, vec3 position, float angle, float size, vec3 color) : VisibleAgent() {
        m_image_id = 0;
        m_pos = position;
        m_angle = angle;
        m_size = size;
        m_color = color;

        m_shader_id = Shader::LoadShader(s_vertex_code, s_fragment_code);

        // Image
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // load and generate the texture
        int width, height, nr_channels;
        unsigned char *data = stbi_load(image.c_str(), &width, &height, &nr_channels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

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

    void Sprite::render() {
        // prepare transformations
        glUseProgram(m_shader_id);
        glm::mat4 model = getModelMatrix();

        glUniformMatrix4fv(glGetUniformLocation(m_shader_id, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniform3f(glGetUniformLocation(m_shader_id, "spriteColor"), m_color.r, m_color.g, m_color.b);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }

    mat4 Sprite::getModelMatrix() {
        // Take rotation and translation into account

        mat4 model = mat4(1.0f);
        model = translate(model, m_pos);
        model = rotate(model, m_angle, vec3(0.0f, 0.0f, 1.0f));
        return model;
    }

    void Sprite::update() {

    }

    void Sprite::renderAll() {
        for (auto &sprite : s_objects) {
            auto *s = dynamic_cast<Sprite *>(sprite);
            if (s) {
                s->render();
            }
        }
    }

} // rdlib