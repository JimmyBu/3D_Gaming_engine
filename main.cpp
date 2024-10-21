#include <iostream>
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <stdlib.h>
#include <stdio.h>

#include "VertexData.h"
#include "ShaderSource.h"
#include "texture2d.h"

using namespace std;

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

GLFWwindow* window;
GLuint vertex_shader, fragment_shader, program;
GLint mvp_location, vpos_location, vcol_location, u_diffuse_texture_location, a_uv_location;
Texture2D* texture_2d = nullptr;

GLuint vao, vbo[2]; // VAO and VBOs

int init_opengl() {
    cout << "Initializing OpenGL" << endl;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(960, 640, "Simple Triangle", NULL, NULL);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cerr << "Failed to initialize GLAD" << endl;
        return -1;
    }

    glfwSwapInterval(1);
    return 0;
}

void compile_shader() {
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    GLint compile_status = GL_FALSE;
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &compile_status);
    if (compile_status == GL_FALSE) {
        GLchar message[256];
        glGetShaderInfoLog(vertex_shader, sizeof(message), 0, message);
        cout << "compile vs error: " << message << endl;
    }

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
    compile_status = GL_FALSE;
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &compile_status);
    if (compile_status == GL_FALSE) {
        GLchar message[256];
        glGetShaderInfoLog(fragment_shader, sizeof(message), 0, message);
        cout << "compile fs error: " << message << endl;
    }

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    GLint link_status = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &link_status);
    if (link_status == GL_FALSE) {
        GLchar message[256];
        glGetProgramInfoLog(program, sizeof(message), 0, message);
        cout << "link error: " << message << endl;
    }
}

void CreateTexture(string image_file_path) {
    texture_2d = Texture2D::loadFromFile(image_file_path);
    if (texture_2d == nullptr) {
        cerr << "Failed to load texture from: " << image_file_path << endl;
    } else {
        cout << "Texture loaded successfully with ID: " << texture_2d->gl_texture_id_ << endl;
    }
}


void setup_vertex_data() {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Positions VBO
    glGenBuffers(1, &vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kPositions), kPositions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(vpos_location); // Enable the position attribute
    glVertexAttribPointer(vpos_location, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // Colors VBO
    glGenBuffers(1, &vbo[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kColors), kColors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(vcol_location); // Enable the color attribute
    glVertexAttribPointer(vcol_location, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // UVs VBO (if you have UVs)
    glGenBuffers(1, &vbo[2]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kUvs), kUvs, GL_STATIC_DRAW);
    glEnableVertexAttribArray(a_uv_location); // Enable the UV attribute
    glVertexAttribPointer(a_uv_location, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindVertexArray(0); // Unbind VAO when done
}


int main(void) {
    if (init_opengl() < 0) return -1;
    string image_file_path = "C:\\Users\\Jimmy\\CLionProjects\\Game_engine\\image\\image.jpg";
    CreateTexture(image_file_path);

    compile_shader();

    mvp_location = glGetUniformLocation(program, "u_mvp");
    vpos_location = glGetAttribLocation(program, "a_pos");
    vcol_location = glGetAttribLocation(program, "a_color");
    a_uv_location = glad_glGetAttribLocation(program, "a_uv");
    u_diffuse_texture_location = glGetUniformLocation(program, "u_diffuse_texture");

    setup_vertex_data(); // Set up vertex data

    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glm::mat4 model, view, projection, mvp;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.3f, 0.3f, 1.f, 0.6f);

        glm::mat4 trans = glm::translate(glm::vec3(0, 0, 0));
        static float rotate_eulerAngle = 0.0f;
        rotate_eulerAngle+=1;
        glm::mat4 rotation = glm::eulerAngleYXZ(glm::radians(rotate_eulerAngle), glm::radians(rotate_eulerAngle), glm::radians(rotate_eulerAngle));
        glm::mat4 scale = glm::scale(glm::vec3(2.0f, 2.0f, 2.0f));
        model = trans * rotation * scale;

        view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
        projection = glm::perspective(glm::radians(60.f), ratio, 1.f, 1000.f);
        mvp = projection * view * model;

        glUseProgram(program);
        {
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);

            glEnableVertexAttribArray(vpos_location);
            glVertexAttribPointer(vpos_location, 3, GL_FLOAT, false, sizeof(glm::vec3), kPositions);

            glEnableVertexAttribArray(vcol_location);
            glVertexAttribPointer(vcol_location, 3, GL_FLOAT, false, sizeof(glm::vec4), kColors);

            glEnableVertexAttribArray(a_uv_location);
            glVertexAttribPointer(a_uv_location, 2, GL_FLOAT, false, sizeof(glm::vec2), kUvs);

            glUniformMatrix4fv(mvp_location, 1, GL_FALSE, &mvp[0][0]);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture_2d->gl_texture_id_);
            glUniform1i(u_diffuse_texture_location, 0);

            glBindVertexArray(vao); // Bind the VAO for drawing
            glDrawArrays(GL_TRIANGLES, 0, 6*6);
            glBindVertexArray(0); // Unbind the VAO
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(2, vbo);

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
