cmake_minimum_required(VERSION 3.10)

project(VexelEmulator)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)

add_executable(emulator src/main.cpp src/framebuffer.cpp)

target_link_libraries(emulator PRIVATE SDL2::SDL2 SDL2::SDL2main)