cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(VCPKG_TARGET_TRIPLET x64-windows-static)


project(repro VERSION 1.0 LANGUAGES CXX)

find_package(OpenImageIO CONFIG REQUIRED)


# Static build fails without it:
find_package(Boost REQUIRED COMPONENTS
    filesystem
    thread)

# Static build on Windows fails without it:
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")


add_executable(test main.cpp)

target_link_libraries(test PRIVATE
        OpenImageIO::OpenImageIO)
