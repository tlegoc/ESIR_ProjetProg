//
// Created by theo on 16/05/23.
//

#include "rdlib/UserInterface.h"

#include "rdlib/Shader.h"
#include "rdlib/TextureManager.h"
#include "rdlib/Engine.h"

#include <GL/glew.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace rdlib {
    // Init static variables
    unsigned int UserInterface::s_shader_id = 0;

    unsigned int UserInterface::s_vao = 0;

    std::string UserInterface::s_vertex_code = "\n"
                                               "#version 330 core\n"
                                               "layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>\n"
                                               "\n"
                                               "out vec2 TexCoords;\n"
                                               "\n"
                                               "uniform mat4 model;\n"
                                               "uniform vec2 size;\n"
                                               "\n"
                                               "void main()\n"
                                               "{\n"
                                               "    TexCoords = vertex.zw;\n"
                                               "    gl_Position = model * vec4(vertex.xy, vertex.y*size.y, 1.0);\n"
                                               "}";

    std::string UserInterface::s_fragment_code = "#version 330 core\n"
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

    std::vector<UserInterface::RenderableElement> UserInterface::m_renderable_elements = {};

    void UserInterface::init() {
        std::cout << "UserInterface::init()" << std::endl;
        if (s_shader_id == 0)
            s_shader_id = Shader::LoadShader(s_vertex_code, s_fragment_code);

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

        glGenVertexArrays(1, &s_vao);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(s_vao);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *) 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void UserInterface::renderImage(const std::string &image, vec2 position, vec2 size, vec3 color, float angle) {
        // prepare transformations
        glUseProgram(s_shader_id);
        unsigned int width = Engine::getWidth();
        unsigned int height = Engine::getHeight();
        float aspect = (float) width / (float) height;
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
        model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(size.x, size.y, 1.0f));
        model = glm::scale(model, glm::vec3(1.0f / aspect, 1.0f, 1.0f));

        glUniformMatrix4fv(glGetUniformLocation(s_shader_id, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniform3f(glGetUniformLocation(s_shader_id, "spriteColor"), color.r, color.g, color.b);
        glUniform2f(glGetUniformLocation(s_shader_id, "size"), size.x, size.y);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, TextureManager::getTexture(image));

        glBindVertexArray(s_vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
        glActiveTexture(0);
    }

    void UserInterface::addImage(const std::string &image, glm::vec2 position, glm::vec2 size, glm::vec3 color,
                                 float angle) {
        RenderableElement element;
        element.image = image;
        element.position = position;
        element.size = size;
        element.color = color;
        element.angle = angle;

        m_renderable_elements.push_back(element);
    }

    void UserInterface::renderAll() {
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        for (auto &element: m_renderable_elements) {
            renderImage(element.image, element.position, element.size, element.color, element.angle);
        }
        clear();
    }

    void UserInterface::clear() {
        m_renderable_elements.clear();
    }
} // rdlib