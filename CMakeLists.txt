cmake_minimum_required(VERSION 3.5.1)
project(zooz_users VERSION 0.1.0)

set(PROJECT_SOURCE_DIR src)

include_directories(include)

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/*.cpp")

add_compile_options("-std=c++11")

add_executable(${PROJECT_NAME} ${SRC_FILES})

