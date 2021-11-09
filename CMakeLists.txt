cmake_minimum_required(VERSION 3.20)
project(untitled5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/menu.cpp src/menu.h)
add_executable(untitled5 ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(untitled5 sfml-graphics sfml-audio sfml-window sfml-system sfml-network)









