cmake_minimum_required(VERSION 3.3)

include_directories(SYSTEM ${CPPREST_INCLUDES})
find_library(CPPREST_LIB NAMES cpprest PATHS ${CPPREST_LIB_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
