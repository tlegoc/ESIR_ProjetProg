//
// Created by theo on 15/05/23.
//

#include "rdlib/Shader.h"

#include <GL/glew.h>
#include <iostream>
#include <vector>

namespace rdlib::Shader {
    unsigned int LoadShader(const std::string &vertex_code, const std::string fragment_code) {
        unsigned int vert_shader = glCreateShader(GL_VERTEX_SHADER);
        unsigned int frag_shader = glCreateShader(GL_FRAGMENT_SHADER);

        // Read shaders

        const char *vertex_code_c = vertex_code.c_str();
        const char *fragment_code_c = fragment_code.c_str();

        int result = GL_FALSE;
        int log_length;

        // Compile vertex shader

        std::cout << "Compiling vertex shader." << std::endl;
        glShaderSource(vert_shader, 1, &vertex_code_c, NULL);
        glCompileShader(vert_shader);

        // Check vertex shader

        glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &result);
        glGetShaderiv(vert_shader, GL_INFO_LOG_LENGTH, &log_length);
        std::vector<char> vert_shader_error((log_length > 1) ? log_length : 1);
        glGetShaderInfoLog(vert_shader, log_length, NULL, &vert_shader_error[0]);
        std::cout << &vert_shader_error[0] << std::endl;

        // Compile fragment shader

        std::cout << "Compiling fragment shader." << std::endl;
        glShaderSource(frag_shader, 1, &fragment_code_c, NULL);
        glCompileShader(frag_shader);

        // Check fragment shader

        glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &result);
        glGetShaderiv(frag_shader, GL_INFO_LOG_LENGTH, &log_length);
        std::vector<char> frag_shader_error((log_length > 1) ? log_length : 1);
        glGetShaderInfoLog(frag_shader, log_length, NULL, &frag_shader_error[0]);
        std::cout << &frag_shader_error[0] << std::endl;

        std::cout << "Linking program" << std::endl;
        GLuint program = glCreateProgram();
        glAttachShader(program, vert_shader);
        glAttachShader(program, frag_shader);
        glLinkProgram(program);

        glGetProgramiv(program, GL_LINK_STATUS, &result);
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
        std::vector<char> programError((log_length > 1) ? log_length : 1);
        glGetProgramInfoLog(program, log_length, NULL, &programError[0]);
        std::cout << &programError[0] << std::endl;

        glDeleteShader(vert_shader);
        glDeleteShader(frag_shader);

        return program;
    }
} // rdlib