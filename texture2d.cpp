//
// Created by Jimmy on 10/9/2024.
//
#include "texture2d.h"
#include <fstream>
#include "stb/stb_image.h"
#include "stopwatch.h"

using std::ofstream;
using std::ios;

Texture2D* Texture2D::loadFromFile(std::string& image_file_path) {
    Texture2D* texture2d = new Texture2D();

    stbi_set_flip_vertically_on_load(true);
    int channels_in_file;

    stopwatch stopwatch;
    stopwatch.start();
    unsigned char* data = stbi_load(image_file_path.c_str(), &(texture2d->width_), &(texture2d->height_), &channels_in_file, 0);
    stopwatch.stop();
    std::int64_t decompress_jpg_cost = stopwatch.milliseconds();

    int image_data_format = GL_RGB;
    // Check if image loading was successful
    if (data == nullptr) {
        // Handle error: loading failed
        std::cerr << "Failed to load texture from " << image_file_path << ": " << stbi_failure_reason() << std::endl;
        delete texture2d; // Clean up to avoid memory leak
        return nullptr;
    }

    // Determine the texture format based on channels
    switch (channels_in_file) {
        case 1:
            image_data_format = GL_RED; // Changed from GL_ALPHA to GL_RED for OpenGL 3.0+
            break;
        case 3:
            image_data_format = GL_RGB;
            texture2d->gl_texture_format_ = GL_COMPRESSED_RGB;
            break;
        case 4:
            image_data_format = GL_RGBA;
            texture2d->gl_texture_format_ = GL_COMPRESSED_RGBA;
            break;
    }

    glGenTextures(1, &(texture2d->gl_texture_id_));
    glBindTexture(GL_TEXTURE_2D, texture2d->gl_texture_id_);

    stopwatch.restart();

    // Use the correct format here
    glTexImage2D(GL_TEXTURE_2D, texture2d->mipmap_level_, texture2d->gl_texture_format_,
             texture2d->width_, texture2d->height_, 0, image_data_format, GL_UNSIGNED_BYTE, data);
    stopwatch.stop();
    std::int64_t upload_and_compress_cost = stopwatch.milliseconds();

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    // Generate mipmaps (if needed)
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    return texture2d;
}

void Texture2D::CompressImageFile(std::string& image_file_path, std::string& saved_image_file_path) {
    Texture2D* texture2d = Texture2D::loadFromFile(image_file_path);

    GLint compress_success = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_COMPRESSED, &compress_success);

    GLint compress_size = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_COMPRESSED_IMAGE_SIZE, &compress_size);

    GLint compress_format = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &compress_format);

    std::vector<char> img(compress_size);
    glGetCompressedTexImage(GL_TEXTURE_2D, 0, img.data());

    ofstream output_file_stream(saved_image_file_path, ios::out | ios::binary);
    if (!output_file_stream.is_open()) {
        std::cerr << "Failed to open file: " << saved_image_file_path << std::endl;
        return;
    }

    CptFileHead cpt_file_head;
    cpt_file_head.type_[0]='c';
    cpt_file_head.type_[1]='p';
    cpt_file_head.type_[2]='t';

    cpt_file_head.mipmap_level_=texture2d->mipmap_level_;
    cpt_file_head.width_=texture2d->width_;
    cpt_file_head.height_=texture2d->height_;
    cpt_file_head.gl_texture_format_=compress_format;
    cpt_file_head.compress_size_=compress_size;

    output_file_stream.write(reinterpret_cast<char*>(&cpt_file_head), sizeof(CptFileHead));
    output_file_stream.write(img.data(), compress_size);
    output_file_stream.close();

}
