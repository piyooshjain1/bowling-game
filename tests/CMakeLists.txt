# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test files
set(TEST_SOURCES
    factory_test/PersonTest.cpp
    factory_test/PlayerTest.cpp
    game_test/BowlingGameTest.cpp
    game_test/FrameTest.cpp
    strategy_test/StandardScoringTest.cpp # Add this if you have scoring tests
)

# Add test executable
add_executable(BowlingGameTests ${TEST_SOURCES})

# Link Google Test libraries and the BowlingGameLib library
target_link_libraries(BowlingGameTests
    GTest::GTest
    GTest::Main
    BowlingGameLib # Link the core game logic library
    pthread
)

# Add tests to CTest
add_test(NAME BowlingGameTests COMMAND BowlingGameTests)

