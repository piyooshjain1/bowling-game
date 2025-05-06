#include "gtest/gtest.h"
#include "../../src/factory/Person.h"

using namespace Game;

// Test the constructor of the Person class
TEST(PersonTest, Constructor) {
    Person person("John");
    EXPECT_EQ(person.getName(), "John");
}

// Test the getName method
TEST(PersonTest, GetName) {
    Person person("Alice");
    EXPECT_EQ(person.getName(), "Alice");
}