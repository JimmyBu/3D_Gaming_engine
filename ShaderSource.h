//
// Created by Jimmy on 10/7/2024.
//

#ifndef SHADERSOURCE_H
#define SHADERSOURCE_H
#pragma region vertex_and_fragment_shader

static const char* vertex_shader_text =
    "#version 330 core\n"

    "uniform mat4 u_mvp;\n"

    "in vec3 a_pos;\n"
    "in vec4 a_color;\n"
    "in vec2 a_uv;\n"

    "out vec4 v_color;\n"
    "out vec2 v_uv;\n"

    "void main()\n"
    "{\n"
    "   gl_Position = u_mvp * vec4(a_pos, 1.0);\n"
    "   v_color = a_color;\n"
    "   v_uv = a_uv;\n"
    "}\n";

static const char* fragment_shader_text =
    "#version 330 core\n"

    "uniform sampler2D u_diffuse_texture;"

    "in vec4 v_color;\n"
    "in vec2 v_uv;\n"

    "out vec4 fragColor;\n"

    "void main()\n"
    "{\n"
    "   fragColor = texture(u_diffuse_texture,v_uv);\n"
    "}\n";

#pragma endregion vertex_and_fragment_shader
#endif //SHADERSOURCE_H
