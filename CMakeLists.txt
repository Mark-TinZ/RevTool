cmake_minimum_required(VERSION 3.0.0)
project(RevTool VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/imgui)
set(
    IMGUI_FILES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/imgui)
include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.h)

add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
    ${IMGUI_FILES}
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
