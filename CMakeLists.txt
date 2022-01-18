cmake_minimum_required(VERSION 3.8.0)

project(dhuum_timer LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GW2_DIR "" CACHE PATH "GW2 Directory")

set(SOURCE
    dhuum_timer/arc_logging.cpp
    dhuum_timer/dhuum_timer.cpp
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
)
include_directories(
    dhuum_timer
    imgui
)

add_library(d3d9_dhuum_timer SHARED
    ${SOURCE}
)
target_compile_definitions(d3d9_dhuum_timer PRIVATE
    UNICODE
    _UNICODE
    _CRT_SECURE_NO_WARNINGS
)
target_compile_options(d3d9_dhuum_timer PUBLIC "/Zc:__cplusplus")
target_link_libraries(d3d9_dhuum_timer PUBLIC
    winmm.dll
)

add_custom_command(TARGET d3d9_dhuum_timer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:d3d9_dhuum_timer> ${GW2_DIR}/bin64/$<TARGET_FILE_NAME:d3d9_dhuum_timer>
)