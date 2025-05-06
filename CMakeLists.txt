# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(BowlingGame CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Enable testing
enable_testing()
# Include directories
include_directories(include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

