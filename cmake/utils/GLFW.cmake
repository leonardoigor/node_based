set(Vendor_DIR ${CMAKE_SOURCE_DIR}/vendor)
project(GLFW)

SET(GLFW_DIR ${Vendor_DIR}/glfw)
include_directories(${GLFW_DIR})

# add_subdirectory(${Vendor_DIR}/glew/build/cmake)
