cmake_minimum_required(VERSION 3.10)

project(VexelEmulator)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)

add_executable(emulator src/main.cpp src/framebuffer.cpp src/vexel_renderer.cpp src/test_patterns/gradient.cpp src/application.cpp src/frame_timer.cpp src/animation/animation.cpp src/animation/procedural_animation.cpp src/animation/procedural_animations/gradient.cpp src/animation/frame_animation.cpp src/animation/frame_animations/moving_pixel.cpp src/animation/animation_controller.cpp src/input_controller.cpp)

target_include_directories(emulator PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(emulator PRIVATE SDL2::SDL2 SDL2::SDL2main)