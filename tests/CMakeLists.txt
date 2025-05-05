set(TEST_SOURCES
    BowlingGameTest.cpp
    ScoringStrategyTest.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(BowlingGameTests ${TEST_SOURCES})

target_link_libraries(BowlingGameTests PRIVATE bowling-game)