cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 17) # Use C++17
set(CMAKE_CXX_STANDARD_REQUIRED True) # Enforce the standar

set(VCPKG_ROOT "C:/Program Files/vcpkg")
set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg.exe")
set(VCPKG_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/)

# Set the output directories for libraries and archives
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)

# Ensure the same output directories for specific configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/bin)

set(VCPKG_LIB_NAMES
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
find_package(OpenGL REQUIRED)

include(cmake/update_modules.cmake)
include(cmake/loadLibraries.cmake)

add_subdirectory(App)