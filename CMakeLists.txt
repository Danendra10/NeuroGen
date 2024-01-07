project(NeuroGen)
cmake_minimum_required(VERSION 3.28.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(logger src/logger/logger.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main logger)