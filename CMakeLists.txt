cmake_minimum_required (VERSION 3.12)

project (bisasam)

set (CMAKE_CXX_STANDARD 11)

set(source_dir "${PROJECT_SOURCE_DIR}/apps/")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(Tutorial "${source_dir}/Main.cpp")

find_package(Crow)
target_link_libraries(Tutorial PUBLIC Crow::Crow)
