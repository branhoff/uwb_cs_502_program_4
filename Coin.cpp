//--------------------------------------------------------------------
// COIN.CPP
// Implementation of the Coin class
// Author: Brandon Hoffman
//--------------------------------------------------------------------
// Coin class:
// Represents a coin item in a store inventory management system.
// Inherits from the Item class and adds the following methods:
// Coin - constructor that initializes the year, grade, and coin type of the coin
// ~Coin - destructor that frees dynamically allocated memory, if any
// getInfo - returns a string representation of the coin, including coin type, year, and grade
// compare - compares this Coin object with another Item object based on their sorting criteria
// Assumptions:
// - The year input is a positive integer
// - The grade and coin type inputs are non-empty strings
//--------------------------------------------------------------------

#include "Coin.h"

/**
 * @brief Constructor for the Coin class to initialize the data members.
 *
 * @pre year is a positive integer.
 *      grade is a non-empty string.
 *      coinType is a non-empty string.
 *
 * @post The year, grade, coinType data members are initialized with the input values,
 *       and the type data member is initialized to 'M'.
 *
 * @param year The year the coin was minted.
 * @param grade The grade of the coin.
 * @param coinType The type of coin.
 */
Coin::Coin(int year, string grade, std::string coinType) : Item('M', year, grade), coinType(coinType) {}

Coin::~Coin() {}

/**
 * @brief Returns a string representation of the coin, including its coin type, year, and grade.
 *
 * @pre None.
 *
 * @post A string representation of the coin, including its coin type, year, and grade, is returned.
 *
 * @return A string representation of the coin, including its coin type, year, and grade.
 */
std::string Coin::getInfo() {
   return "Coin: " + coinType + " (" + std::to_string(year) + "), Grade: " + grade;
}

/**
 * @brief Compares this Coin object with another Item object based on their sorting criteria.
 *
 * @pre The other object is a pointer to an Item object.
 *
 * @post Returns an integer based on the comparison of the two objects.
 *       If this Coin should come before the other object in the sorting order, returns -1.
 *       If the other object should come before this Coin in the sorting order, returns 1.
 *       If the two objects are equal in their sorting order, returns 0.
 *
 * @param other A pointer to the other Item object to compare to.
 *
 * @return An integer based on the comparison of the two objects.
 */
int Coin::compare(Item* other) {
   Coin* otherCoin = dynamic_cast<Coin*>(other);
   if (otherCoin == nullptr)
      return -1;

   if (coinType < otherCoin->coinType)
      return -1;
   if (coinType > otherCoin->coinType)
      return 1;

   if (year < otherCoin->year)
      return -1;
   if (year > otherCoin->year)
      return 1;

   if (grade < otherCoin->grade)
      return -1;
   if (grade > otherCoin->grade)
      return 1;

   return 0;
}