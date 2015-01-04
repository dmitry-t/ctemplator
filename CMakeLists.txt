cmake_minimum_required(VERSION 2.8)

project(CTemplator)

set(CMAKE_BUILD_TYPE "Debug")
add_compile_options(-std=c++11)

include_directories(${PROJECT_SOURCE_DIR} /usr/local/include)
link_directories(/usr/local/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_subdirectory(ctemplator)
