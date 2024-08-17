cmake_minimum_required(VERSION 3.11)

project(App)

add_executable(App main.cpp Editor.cpp)

target_link_libraries(App PUBLIC vendor::imgui)
target_link_libraries(App PUBLIC vendor::imnode)