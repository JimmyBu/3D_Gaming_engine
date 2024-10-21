cmake_minimum_required(VERSION 3.29)
project(Game_engine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Set GLFW and GLAD directories
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/glfw-3.4")
set(GLAD_DIR "${CMAKE_SOURCE_DIR}/glad")
set(GLM_DIR "${CMAKE_SOURCE_DIR}/glm")
set(STB_DIR "${CMAKE_SOURCE_DIR}")

# Include directories for GLFW and GLAD
include_directories(${GLFW_DIR}/include)
include_directories(${GLAD_DIR}/include)
include_directories(${GLM_DIR})
include_directories(${STB_DIR})

# Link GLFW library
link_directories(${GLFW_DIR}/lib-mingw-w64)

# Specify the executable and the source files
add_executable(Game_engine main.cpp ${GLAD_DIR}/src/gl.c
        texture2d.h
        texture2d.cpp
        stopwatch.h)

# Link libraries
target_link_libraries(Game_engine PRIVATE glfw3 opengl32)

# Ensure that the GLAD source is compiled
set_target_properties(Game_engine PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON)
