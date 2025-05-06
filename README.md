# Bowling Game

This project implements a Bowling Game using C++ and demonstrates the use of clean code principles, including the **SOLID principles**, the **Strategy Pattern**, and a centralized **Logger Utility** for logging.

---

## Design Principles and Patterns Used

### **1. SOLID Principles**
The codebase adheres to the SOLID principles of object-oriented design:

1. **Single Responsibility Principle (SRP)**:
   - Each class has a single responsibility:
     - `Player`: Manages player-specific details like rolls and frames.
     - `Frame`: Manages the state of a single frame (e.g., rolls, strikes, spares).
     - `BowlingGame`: Manages the overall game logic, including players and scoring.
     - `StandardScoring`: Encapsulates the scoring logic for the game.
     - `Logger`: Handles centralized logging for the application.
   - This separation ensures that changes in one part of the code (e.g., scoring logic) do not affect unrelated parts.

2. **Open/Closed Principle (OCP)**:
   - The `IScoringStrategy` interface allows the scoring logic to be extended without modifying existing code. For example, you can add a new scoring strategy (e.g., `CustomScoring`) by implementing the `IScoringStrategy` interface.

3. **Liskov Substitution Principle (LSP)**:
   - The `StandardScoring` class can be substituted wherever the `IScoringStrategy` interface is used. This ensures that the `BowlingGame` class works seamlessly with any scoring strategy.

4. **Interface Segregation Principle (ISP)**:
   - The `IScoringStrategy` interface is focused solely on scoring logic, ensuring that classes implementing it (e.g., `StandardScoring`) are not forced to implement unrelated methods.

5. **Dependency Inversion Principle (DIP)**:
   - The `BowlingGame` class depends on the `IScoringStrategy` abstraction rather than a concrete implementation. This allows the scoring logic to be easily swapped or extended.

---

### **2. Strategy Pattern**
The **Strategy Pattern** is used to encapsulate the scoring logic. The `IScoringStrategy` interface defines the contract for scoring strategies, and the `StandardScoring` class provides the default implementation based on the rules of bowling.

---

### **3. Logger Utility**
The `Logger` utility is a centralized and thread-safe logging system designed to provide consistent and configurable logging throughout the application. It supports multiple log levels and allows developers to control the verbosity of logs dynamically.

---

## Project Structure

- `src/main.cpp`: Entry point of the application.
- `src/game/`: Contains the game logic and frame management.
- `src/strategy/`: Contains the scoring strategies.
- `src/factory/`: Contains the `Player` and `Person` classes.
- `src/utils/`: Contains the `Logger` utility for centralized logging.
- `include/`: Public header files for external access.
- `tests/`: Contains unit tests for the game logic and strategies.
- `CMakeLists.txt`: Build configuration for the project.
- `README.md`: Documentation for the project.

---

## Rules of Bowling

The game of bowling consists of 10 frames. Each frame allows the player to roll the ball up to two times to knock down 10 pins. The rules for scoring are as follows:

1. **Strike**:
   - A strike occurs when all 10 pins are knocked down on the first roll of a frame.
   - The score for a strike is 10 plus the total number of pins knocked down in the next two rolls.

2. **Spare**:
   - A spare occurs when all 10 pins are knocked down in two rolls of a frame.
   - The score for a spare is 10 plus the number of pins knocked down in the next roll.

3. **Open Frame**:
   - An open frame occurs when fewer than 10 pins are knocked down after two rolls.
   - The score for an open frame is the total number of pins knocked down in that frame.

4. **10th Frame**:
   - In the 10th frame, if a player rolls a strike or a spare, they are awarded one or two additional rolls, respectively.

---

## Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/piyooshjain1/bowling-game.git
   ```

2. Navigate to the project directory:
   ```bash
   cd bowling-game
   ```

3. Create a build directory and navigate into it:
   ```bash
   mkdir build && cd build
   ```

4. Run CMake to configure the project:
   ```bash
   cmake ..
   ```

5. Build the project:
   ```bash
   make
   ```

6. Run the application:
   ```bash
   ./bowling-game
   ```

## Usage

Once the application is running, you can start a new game, add players, and observe the scoring in real-time. The design allows for easy extension, such as adding new scoring strategies or player types.

### Example Usage

```cpp
#include "game/BowlingGame.h"
#include "strategy/StandardScoring.h"

int main() {
   using namespace Game;

   // Create a BowlingGame instance
   BowlingGame game;

   // Add players to the game
   game.addPlayer("Alice");
   game.addPlayer("Bob");

   // Example rolls for the game
   std::vector<int> inputRolls = {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};
   game.printPlayerNames();
   game.selectPlayerByIndex(0); // Select the first player (Alice)
   // Simulate the game by adding rolls
   for (int pins : inputRolls) {
      try {
         game.addRoll(pins);
      } catch (const std::logic_error& e) {
         std::cerr << "Error: " << e.what() << std::endl;
         break;
      }
   }
   // Display results
   game.displayResult();

   return 0;
}
```

---

## Running Test Cases

The project includes unit tests to verify the correctness of the game logic and scoring strategies.

### Steps to Run Tests

1. Navigate to the build directory:
   ```bash
   cd build
   ```

2. Build the test suite:
   ```bash
   make
   ```

3. Run the test executable directly:
   ```bash
   ./tests/BowlingGameTests
   ```

4. View the test results:
   ```
   [==========] 23 tests from 5 test suites ran. (0 ms total)
   [  PASSED  ] 23 tests.
   ```
