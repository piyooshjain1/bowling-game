# Bowling Game

This project implements a Bowling Game using C++ and demonstrates the use of several design patterns, including Strategy, Factory, and Observer.

## Design Patterns Used

1. **Strategy Pattern**: 
   - The scoring strategy for the game is encapsulated in different classes that implement the `ScoringStrategy` interface. This allows for flexible scoring methods that can be changed at runtime.

2. **Factory Pattern**: 
   - The `PlayerFactory` class is responsible for creating player instances. This abstracts the instantiation process and allows for easy modifications in player creation logic.

3. **Observer Pattern**: 
   - The `ScoreObserver` class observes changes in the game's score. The `Subject` class maintains a list of observers and notifies them of any score changes, allowing for a dynamic update of the game's state.

## Project Structure

- `src/main.cpp`: Entry point of the application.
- `src/game/`: Contains the game logic and frame management.
- `src/strategy/`: Contains the scoring strategies.
- `src/factory/`: Contains the player creation logic.
- `src/observer/`: Contains the observer pattern implementation.
- `include/bowling-game/`: Public header files for external access.
- `tests/`: Contains unit tests for the game logic and strategies.
- `CMakeLists.txt`: Build configuration for the project.
- `README.md`: Documentation for the project.

## Setup Instructions

1. Clone the repository:
   ```
   git clone <repository-url>
   ```

2. Navigate to the project directory:
   ```
   cd bowling-game
   ```

3. Create a build directory and navigate into it:
   ```
   mkdir build && cd build
   ```

4. Run CMake to configure the project:
   ```
   cmake ..
   ```

5. Build the project:
   ```
   make
   ```

6. Run the application:
   ```
   ./bowling-game
   ```

## Usage

Once the application is running, you can start a new game, add players, and observe the scoring in real-time. The design allows for easy extension, such as adding new scoring strategies or player types.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.