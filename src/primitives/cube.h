#pragma once

#include <memory>
#include <array>

#include "../graphic/vertex_array.h"
#include "../graphic/data_buffer.h"
#include "../graphic/index_buffer.h"

class Cube {
private:
    std::unique_ptr<VertexArray> vertex_array_;
    std::unique_ptr<DataBuffer> data_buffer_;
    std::unique_ptr<IndexBuffer> index_buffer_;
    std::array<float, 288> data_ {
        //=======verices====    ======normals======   =====uv====   ===========color=======
        // forward
        -1.0f, -1.0f,  1.0f,    0.0f,  0.0f,  1.0f,   0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f, -1.0f,  1.0f,    0.0f,  0.0f,  1.0f,   1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,    0.0f,  0.0f,  1.0f,   1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f,  1.0f,    0.0f,  0.0f,  1.0f,   0.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        // back
        -1.0f, -1.0f, -1.0f,    0.0f,  0.0f, -1.0f,   0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f, -1.0f, -1.0f,    0.0f,  0.0f, -1.0f,   1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f,  1.0f, -1.0f,    0.0f,  0.0f, -1.0f,   1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, -1.0f,    0.0f,  0.0f, -1.0f,   0.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        // right
         1.0f, -1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f,  1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   0.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        // left
        -1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,   1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,   1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        // top
        -1.0f,  1.0f,  1.0f,    0.0f,  1.0f,  0.0f,   0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,    0.0f,  1.0f,  0.0f,   1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f,  1.0f, -1.0f,    0.0f,  1.0f,  0.0f,   1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, -1.0f,    0.0f,  1.0f,  0.0f,   0.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        // bottom
        -1.0f, -1.0f,  1.0f,    0.0f, -1.0f,  0.0f,   0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f, -1.0f,  1.0f,    0.0f, -1.0f,  0.0f,   1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
         1.0f, -1.0f, -1.0f,    0.0f, -1.0f,  0.0f,   1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,    0.0f, -1.0f,  0.0f,   0.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
        //=======verices====    ======normals======   =====uv====   ===========color=======
    };
    std::array<int, 36> indices_ {
        0, 1, 2,
        0, 2, 3,
        8, 9, 10,
        8, 10, 11,
        5, 4, 7,
        5, 7, 6,
        13, 12, 15,
        13, 15, 14,
        16, 17, 18,
        16, 18, 19,
        21, 20, 23,
        21, 23, 22,
    };
public:
    Cube();
    ~Cube() = default;
    void bind();
    void unbind();
};

