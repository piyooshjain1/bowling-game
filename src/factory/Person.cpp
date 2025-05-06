/**
 * @file Person.cpp
 * @brief Implementation of the Person class, which represents a person in the game.
 */
#include "Person.h"
namespace Game {

/**
 * @brief Constructs a Person object with the given name.
 * @param name The name of the person.
 */
Person::Person(const std::string& name) : name(name) {}

/**
 * @brief Retrieves the name of the person.
 * @return A constant reference to the name of the person.
 */
const std::string Person::getName() const {
    return name;
}

} // namespace Game

