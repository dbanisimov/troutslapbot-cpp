cmake_minimum_required(VERSION 3.3)
project(slap)

set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# cpprestsdk
set(BUILD_TESTS OFF CACHE BOOL "Build tests.")
set(BUILD_SAMPLES OFF CACHE BOOL "Build samples.")
add_subdirectory(lib/cpprestsdk/Release)

include_directories(SYSTEM lib/cpprestsdk/Release/include)

# bot
add_subdirectory(src)
