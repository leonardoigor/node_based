cmake_minimum_required(VERSION 3.11)
set(Vendor_DIR ${CMAKE_SOURCE_DIR}/vendor)

SET(GLEW_DIR ${Vendor_DIR}/glew)
project(App)

include_directories(${CMAKE_SOURCE_DIR}/vendor/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glew/auto/src)

set(VcpkgEnableManifest TRUE)
include_directories(${GLEW_DIR}/include)
include_directories(include)

add_executable(App main.cpp src/Editor.cpp include/Editor.h)
set(VCPKG_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

target_link_libraries(App PUBLIC OpenGL::GL)
target_link_libraries(App PUBLIC vendor::imgui)
target_link_libraries(App PUBLIC vendor::imnode)
target_link_libraries(App PUBLIC glfw)

target_link_libraries(App PRIVATE vendor::glew)

target_link_libraries(App PRIVATE glad::glad)

set(pathstoCopty
    lib
    bin
)

foreach(path ${pathstoCopty})
    # Adicione um alvo para copiar os arquivos após a construção
    add_custom_command(TARGET App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${VCPKG_INSTALLED_DIR}/${path}/"
        ${CMAKE_SOURCE_DIR}/output
        COMMENT "Copying all items from ${SOURCE_DIR} to ${DESTINATION_DIR}"
    )
endforeach()