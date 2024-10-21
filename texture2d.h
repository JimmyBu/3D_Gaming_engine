//
// Created by Jimmy on 10/8/2024.
//

#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <glad/gl.h>

class Texture2D {
private:
    Texture2D():mipmap_level_(0){};
    ~Texture2D(){};

public:
    static Texture2D* loadFromFile(std::string& image_file_path);
    static void CompressImageFile(std::string& image_file_path, std::string& saved_image_file_path);

public:
    int mipmap_level_;
    int width_;
    int height_;

    GLenum gl_texture_format_;
    GLuint gl_texture_id_;

    struct CptFileHead {
        char type_[3];
        int mipmap_level_;
        int width_;
        int height_;
        int gl_texture_format_;
        int compress_size_;
    };
};

#endif //TEXTURE2D_H
