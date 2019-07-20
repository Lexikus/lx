#pragma once

#include "camera_type.h"

#include <glm/glm.hpp>

class Camera {
private:
    CameraType camera_type_ { CameraType::None };
    glm::mat4 projection_matrix_ { 1 };
    glm::mat4 view_matrix_ { 1 };
    glm::mat4 view_projection_matrix_ { 1 };
    glm::vec3 position_ { 1 };
public:
    Camera() = default;
    void create_perspective(float fovy, float aspect, float near, float far);
    const glm::mat4& get_projection() const;
    const glm::mat4& get_view() const;
    const glm::mat4& get_view_projection() const;
};


