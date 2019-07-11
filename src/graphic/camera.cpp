#include "camera.h"

#include "camera_type.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void Camera::create_perspective(float fovy, float aspect, float near, float far) {
    if (near < 0){
        near = 0;
    }
    if (far < 0){
        far = 0;
    }

    projection_matrix_ = glm::perspective<float>(fovy, (float)aspect, near, far);
    camera_type_ = CameraType::Perspective;
}

const glm::mat4& Camera::get_projection() const {
    return projection_matrix_;
}

const glm::mat4& Camera::get_view() const {
    return view_matrix_;
}

const glm::mat4& Camera::get_view_projection() const {
    return view_projection_matrix_;
}
