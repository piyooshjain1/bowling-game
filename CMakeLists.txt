# Set the project name and C++ standard
project(bowling-game)
set(CMAKE_CXX_STANDARD 17)

# Include header files
target_include_directories(bowling-game PRIVATE include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(bowling-game ${SOURCES})

# Enable testing and add test directory
enable_testing()
add_subdirectory(tests)