/**
 * @file Person.h
 * @brief Defines the Person class used in the Game namespace.
 * 
 * This file contains the declaration of the Person class, which represents
 * a person with a name in the context of the bowling game application.
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace Game {

/**
 * @class Person
 * @brief Represents a person with a name.
 * 
 * The Person class provides functionality to store and retrieve the name
 * of a person.
 */
class Person {
private:
    std::string name; ///< The name of the person.

public:
    /**
     * @brief Constructs a Person object with the given name.
     * @param name The name of the person.
     */
    explicit Person(const std::string& name);

    /**
     * @brief Retrieves the name of the person.
     * @return A constant reference to the name of the person.
     */
    const std::string getName() const;
};

} // namespace Game

#endif // PERSON_H