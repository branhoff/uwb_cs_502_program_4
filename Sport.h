//--------------------------------------------------------------------
// SPORT.H
// Declaration of the Sport class
// Author: Brandon Hoffman
//--------------------------------------------------------------------
// Sport class:
//   Represents a sport item in a store inventory management system.
//   Inherits from the Item class and adds the following methods:
//      Sport - constructor that initializes the year, grade, player, and manufacturer of the sport item
//      getInfo - returns a string representation of the sport item, including player name, year, grade, and manufacturer
//      compare - compares two sport items based on their sorting criteria
//   Assumptions:
//      - The year input is a positive integer
//      - The grade, player, and manufacturer inputs are non-empty strings
//--------------------------------------------------------------------

#pragma once

#include "Item.h"

class Sport : public Item
{
public:
   /**
    * @brief Constructor for Sport class to initialize the data members.
    *
    * @param year The year the sport card was made.
    * @param grade The grade of the sport card.
    * @param player The name of the athlete on the card.
    * @param manufacturer The name of the card's manufacturer.
    *
    * @pre year is a positive integer.
    *      grade is a non-empty string.
    *      player is a non-empty string.
    *      manufacturer is a non-empty string.
    *
    * @post The year, grade, player and manufacturer data members are initialized with the input values.
    */
   Sport(int year, string grade, string player, string manufacturer);

   /**
    * @brief Returns a string representation of the sport item, including player name, year, grade, and manufacturer.
    *
    * @pre None.
    *
    * @post A string representation of the sport item is returned.
    *
    * @return A string representation of the sport item, including player name, year, grade, and manufacturer.
    */
   virtual std::string getInfo() override;

   /**
    * @brief Compares two sport items based on their sorting criteria.
    *
    * @pre None.
    *
    * @post If this sport item is considered "less than" the other item, -1 is returned.
    *       If they are considered "equal", 0 is returned. Otherwise, 1 is returned.
    *
    * @param other The other item to compare to.
    *
    * @return -1 if this item is "less than" the other item, 0 if they are "equal", and 1 if this item is "greater than" the other item.
    */
   virtual int compare(Item* other) override;

private:
   string player;
   string manufacturer;
};

