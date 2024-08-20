set(Vendor_DIR ${CMAKE_SOURCE_DIR}/vendor)
project(Glew C)

SET(GLEW_DIR ${Vendor_DIR}/glew)

file(GLOB_RECURSE headers ${GLEW_DIR}/include/*.hpp ${GLEW_DIR}/include/*.h)
file(GLOB sources ${GLEW_DIR}/src/*.cpp ${GLEW_DIR}/src/*.c)

# Add the library target as C
add_library(glew STATIC ${sources} ${headers})

# Ensure GLEW_STATIC is defined to avoid linking issues
target_compile_definitions(glew PUBLIC GLEW_STATIC)

target_include_directories(glew PUBLIC ${GLEW_DIR}/include)

add_library(vendor::glew ALIAS glew)
set_property(TARGET glew PROPERTY C_STANDARD 99)