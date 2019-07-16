target_sources(${PROJECT_NAME}
    PRIVATE
        # ${CMAKE_CURRENT_SOURCE_DIR}/primitive.h
        # ${CMAKE_CURRENT_SOURCE_DIR}/cube.h ${CMAKE_CURRENT_SOURCE_DIR}/cube.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})