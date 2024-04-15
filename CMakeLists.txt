cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project(repro VERSION 1.0 LANGUAGES CXX)

find_package(OpenColorIO CONFIG REQUIRED)
