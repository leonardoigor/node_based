set(Vendor_DIR ${CMAKE_SOURCE_DIR}/vendor)
project(ImGui)

SET(IMGUI_DIR ${Vendor_DIR}/imgui)
set(sources
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
)

set(headers
    ${IMGUI_DIR}/imgui.h
    ${IMGUI_DIR}/imgui_internal.h
    ${IMGUI_DIR}/imconfig.h
    ${IMGUI_DIR}/imstb_rectpack.h
    ${IMGUI_DIR}/imstb_textedit.h
    ${IMGUI_DIR}/imstb_truetype.h
)

# Add the library target
add_library(imgui ${sources} ${headers})

target_include_directories(imgui PUBLIC ${IMGUI_DIR})

add_library(vendor::imgui ALIAS imgui)
