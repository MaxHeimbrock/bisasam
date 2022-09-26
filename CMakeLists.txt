cmake_minimum_required (VERSION 3.12)

project (bisasam)

set (CMAKE_CXX_STANDARD 14)
include(FetchContent)
SET(CMAKE_OSX_DEPLOYMENT_TARGET 12.0)

set(source_dir "${PROJECT_SOURCE_DIR}/apps/")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(Tutorial "${source_dir}/Main.cpp")

# using local Crow header directory
target_include_directories(Tutorial PRIVATE ${CMAKE_BINARY_DIR}/extern/Crow/include)
target_include_directories(Tutorial PRIVATE ${CMAKE_BINARY_DIR}/extern/asio/asio/include)

# ========== CATCH2 ====================================================

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# ========== TESTS =====================================================

add_executable(tests ${PROJECT_SOURCE_DIR}/tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Tutorial PRIVATE Threads::Threads)
