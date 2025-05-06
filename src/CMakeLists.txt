# Define the project name and version
cmake_minimum_required(VERSION 3.10)
project(BowlingGame VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    factory/Person.cpp
    game/BowlingGame.cpp
    game/Frame.cpp
    strategy/StandardScoring.cpp
    factory/Player.cpp  # Ensure this is included
    utils/Logger.cpp
)
# Create a library target for the game logic
add_library(BowlingGameLib ${SOURCES})

# Add the main executable
add_executable(BowlingGame main.cpp)

# Add include directories
target_include_directories(BowlingGameLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/strategy
    ${CMAKE_CURRENT_SOURCE_DIR}/game
    ${CMAKE_CURRENT_SOURCE_DIR}/factory/
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)



# Link the library to the executable
target_link_libraries(BowlingGame PRIVATE BowlingGameLib)

# Include directories (if needed)
# Example: target_include_directories(BowlingGameLib PRIVATE include)