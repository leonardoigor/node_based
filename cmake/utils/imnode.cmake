
set(Vendor_DIR ${CMAKE_SOURCE_DIR}/vendor)
project(ImNode)

SET(ImNode_DIR ${Vendor_DIR}/imnodes)

file(GLOB sources ${ImNode_DIR}/*.cpp)
file(GLOB headers ${ImNode_DIR}/*.h ${ImNode_DIR}/*.hpp)

# Add the library target
add_library(imnode ${sources} ${headers})
target_include_directories(imnode PUBLIC ${ImNode_DIR})

target_link_libraries(imnode PUBLIC vendor::imgui)

add_library(vendor::imnode ALIAS imnode)
