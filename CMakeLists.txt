cmake_minimum_required (VERSION 3.12)

project (bisasam)

set (CMAKE_CXX_STANDARD 11)

set(source_dir "${PROJECT_SOURCE_DIR}/apps/")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(Tutorial "${source_dir}/Main.cpp")

# using local Crow header directory
# target_include_directories(Tutorial PRIVATE ${CMAKE_BINARY_DIR}/extern/Crow/include)
# target_include_directories(Tutorial PRIVATE /usr/local/include)
# target_include_directories(Tutorial PRIVATE /usr/local/Cellar/asio/include)

# using installed Crow directory, which also finds asio for me
find_package(Crow)
target_link_libraries(Tutorial PUBLIC Crow::Crow)
