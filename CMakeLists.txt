cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(lx VERSION 0.0.1 LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_options(lx PRIVATE -Werror -Wall -Wextra)

# glfw
# lib requirements xorg-dev libglu1-mesa-dev
add_subdirectory(vendor/glfw)
target_link_libraries(${PROJECT_NAME} glfw)
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})

# glad
add_subdirectory(vendor/glad)
target_link_libraries(${PROJECT_NAME} glad)

# glm
set (GLM_TEST_ENABLE OFF)
add_subdirectory(vendor/glm)
target_link_libraries(${PROJECT_NAME} glm)