cmake_minimum_required(VERSION 3.11)

project(App)

include_directories(${CMAKE_SOURCE_DIR}/vendor/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glew/auto/src)

add_executable(App main.cpp Editor.cpp)

target_link_libraries(App PUBLIC vendor::imgui)
target_link_libraries(App PUBLIC vendor::imnode)
target_link_libraries(App PUBLIC glfw)

target_link_libraries(App PUBLIC glew)

# target_link_libraries(App PRIVATE glad::glad)
# target_link_libraries(App PRIVATE glfw)