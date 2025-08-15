cmake_minimum_required(VERSION 4.0.2)
project(PongRaylib VERSION 1.0.0)

set(mainFolder ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/game_bin")

include_directories(include)
link_directories(lib)
file(GLOB SOURCE_FILES "src/*.c")

add_executable(PongRaylib ${SOURCE_FILES} program.rc)
target_link_libraries(PongRaylib raylib)
target_compile_definitions(PongRaylib PRIVATE GAME_THEME=0)