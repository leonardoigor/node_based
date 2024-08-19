cmake_minimum_required(VERSION 3.11)

set(VCPKG_ROOT "C:/Program Files/vcpkg")
set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg.exe")
set(VCPKG_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

set(VCPKG_LIB_NAMES
    glew
    glad
    glfw3
)

execute_process(
    COMMAND ${VCPKG_EXECUTABLE} install
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE VCPKG_RESULT
)

if(NOT VCPKG_RESULT EQUAL 0)
    message(FATAL_ERROR "vcpkg install failed with error code ${VCPKG_RESULT}")
endif()

foreach(item ${VCPKG_LIB_NAMES})
    set("${item}_DIR" ${VCPKG_INSTALLED_DIR}/share/${item})
    message(STATUS "Library VCPKG LINK ${item}_DIR = ${${item}_DIR}")
endforeach()

include_directories(${VCPKG_INSTALLED_DIR}/include)
link_directories(${VCPKG_INSTALLED_DIR}/lib)
link_directories(${VCPKG_INSTALLED_DIR}/bin)

# Project setup
find_package(glad CONFIG REQUIRED)

# find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)

include(cmake/update_modules.cmake)
include(cmake/loadLibraries.cmake)

add_subdirectory(App)