cmake_minimum_required(VERSION 3.3)

include_directories(SYSTEM ${CPPREST_INCLUDES})
find_library(CPPREST_LIB NAMES cpprest PATHS ${CPPREST_LIB_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

set(SOURCES
  slap.cpp
  telegram_bot.cc
  trout_slap_bot.cc
)

set(HEADERS
  telegram_bot.h
  telegram_exceptions.h
  trout_slap_bot.h
)

add_executable(slap ${SOURCES} ${HEADERS})
target_link_libraries(slap ${CPPREST_LIB})
