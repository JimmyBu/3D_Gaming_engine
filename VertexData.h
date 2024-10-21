//
// Created by Jimmy on 10/7/2024.
//

#ifndef VERTEXDATA_H
#define VERTEXDATA_H
#include <glm/glm.hpp>

static const glm::vec3 kPositions[36] = {
    // front
    glm::vec3{-1.0f, -1.0f, 1.0f},
    glm::vec3{1.0f, -1.0f, 1.0f},
    glm::vec3{1.0f, 1.0f, 1.0f},

    glm::vec3{-1.0f, -1.0f, 1.0f},
    glm::vec3{1.0f, 1.0f, 1.0f},
    glm::vec3{-1.0f, 1.0f, 1.0f},

    // back
    glm::vec3{1.0f, -1.0f, -1.0f},
    glm::vec3{-1.0f, -1.0f, -1.0f},
    glm::vec3{-1.0f, 1.0f, -1.0f},

    glm::vec3{1.0f, -1.0f, -1.0f},
    glm::vec3{-1.0f, 1.0f, -1.0f},
    glm::vec3{1.0f, 1.0f, -1.0f},

    // left
    glm::vec3{-1.0f, -1.0f, -1.0f},
    glm::vec3{-1.0f, -1.0f, 1.0f},
    glm::vec3{-1.0f, 1.0f, 1.0f},

    glm::vec3{-1.0f, -1.0f, -1.0f},
    glm::vec3{-1.0f, 1.0f, 1.0f},
    glm::vec3{-1.0f, 1.0f, -1.0f},

    // right
    glm::vec3{1.0f, -1.0f, 1.0f},
    glm::vec3{1.0f, -1.0f, -1.0f},
    glm::vec3{1.0f, 1.0f, -1.0f},

    glm::vec3{1.0f, -1.0f, 1.0f},
    glm::vec3{1.0f, 1.0f, -1.0f},
    glm::vec3{1.0f, 1.0f, 1.0f},

    // up
    glm::vec3{-1.0f, 1.0f, 1.0f},
    glm::vec3{1.0f, 1.0f, 1.0f},
    glm::vec3{1.0f, 1.0f, -1.0f},

    glm::vec3{-1.0f, 1.0f, 1.0f},
    glm::vec3{1.0f, 1.0f, -1.0f},
    glm::vec3{-1.0f, 1.0f, -1.0f},

    // down
    glm::vec3{-1.0f, -1.0f, -1.0f},
    glm::vec3{1.0f, -1.0f, -1.0f},
    glm::vec3{1.0f, -1.0f, 1.0f},

    glm::vec3{-1.0f, -1.0f, -1.0f},
    glm::vec3{1.0f, -1.0f, 1.0f},
    glm::vec3{-1.0f, -1.0f, 1.0f},
};

static const glm::vec4 kColors[36] = {
    // front
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},

    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},

    // back
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},

    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},
    glm::vec4{1.0f, 0.0f, 0.0f, 1.0f},

    // left
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},

    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},

    // right
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},

    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},
    glm::vec4{0.0f, 1.0f, 0.0f, 1.0f},

    // up
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},

    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},

    // down
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},

    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
    glm::vec4{0.0f, 0.0f, 1.0f, 1.0f},
};

static const glm::vec2 kUvs[36] = {
    // Front
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),

    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // back
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),

    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // left
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),

    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // right
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),

    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // up
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),

    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),

    // down
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),

    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f),
};


#endif //VERTEXDATA_H
