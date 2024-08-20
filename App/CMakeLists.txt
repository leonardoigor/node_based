cmake_minimum_required(VERSION 3.11)

project(App)

include_directories(${CMAKE_SOURCE_DIR}/vendor/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glew/auto/src)

set(GLEW_INCLUDE_DIRS "${VCPKG_INSTALLED_DIR}/include")
set(GLEW_LIBRARIES "${VCPKG_INSTALLED_DIR}/lib/")
set(VcpkgEnableManifest TRUE)
include_directories(${GLEW_INCLUDE_DIRS})

add_executable(App main.cpp Editor.cpp)
set(VCPKG_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

# Adicione um alvo para copiar os arquivos após a construção
add_custom_command(TARGET App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${VCPKG_INSTALLED_DIR}/lib/"
    ${CMAKE_SOURCE_DIR}/output
    COMMENT "Copying all items from ${SOURCE_DIR} to ${DESTINATION_DIR}"
)

target_link_libraries(App PUBLIC vendor::imgui)
target_link_libraries(App PUBLIC vendor::imnode)
target_link_libraries(App PUBLIC glfw)

# Link against GLEW based on build type
if(MSVC)
    target_link_libraries(App PRIVATE glew)
else()
    target_link_libraries(App PRIVATE ${GLEW_LIBRARIES})
endif()

target_link_libraries(App PRIVATE glad::glad)
