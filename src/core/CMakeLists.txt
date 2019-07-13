target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/keyboard.h ${CMAKE_CURRENT_SOURCE_DIR}/keyboard.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/input.h ${CMAKE_CURRENT_SOURCE_DIR}/input.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/window.h ${CMAKE_CURRENT_SOURCE_DIR}/window.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})