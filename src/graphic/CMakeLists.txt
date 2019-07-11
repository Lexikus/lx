target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/context.h ${CMAKE_CURRENT_SOURCE_DIR}/context.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/shader_type.h
        ${CMAKE_CURRENT_SOURCE_DIR}/shader.h ${CMAKE_CURRENT_SOURCE_DIR}/shader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/program.h ${CMAKE_CURRENT_SOURCE_DIR}/program.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vertex_array.h ${CMAKE_CURRENT_SOURCE_DIR}/vertex_array.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/buffer_data_type.h ${CMAKE_CURRENT_SOURCE_DIR}/buffer_data_type.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/buffer_element.h ${CMAKE_CURRENT_SOURCE_DIR}/buffer_element.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/data_buffer.h ${CMAKE_CURRENT_SOURCE_DIR}/data_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/index_buffer.h ${CMAKE_CURRENT_SOURCE_DIR}/index_buffer.cpp
        ${CMAKE_HOME_DIRECTORY}/vendor/stb/stb_image.h
        ${CMAKE_CURRENT_SOURCE_DIR}/texture.h ${CMAKE_CURRENT_SOURCE_DIR}/texture.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/camera_type.h
        ${CMAKE_CURRENT_SOURCE_DIR}/camera.h ${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})