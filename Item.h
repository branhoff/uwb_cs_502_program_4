//--------------------------------------------------------------------
// ITEM.H
// Declaration of the Item class
// Author: Brandon Hoffman
//--------------------------------------------------------------------
// Item class:
// Represents an item in a store inventory management system.
// Provides the following methods:
// Item - constructor that initializes the type, year, and grade of the item
// getInfo - returns an empty string (to be overridden in child classes)
// compare - compares two items based on their sorting criteria (to be overridden in child classes)
// setCount - sets the count of the item to a given value
// Assumptions:
// - The type input is a valid item type, i.e. 'M' for Coins, 'C' for Comic books, 'S' for Sports cards
// - The year input is a positive integer
// - The grade input is a non-empty string
//--------------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
   /**
    * @brief Constructor for the Item class to initialize the data members.
    *
    * @param type The type of item ('M' for Coins, 'C' for Comic books, 'S' for Sports cards).
    * @param year The year the item was made.
    * @param grade The grade of the item.
    *
    * @pre type is a valid item type, i.e. 'M' for Coins, 'C' for Comic books, 'S' for Sports cards.
    *      year is a positive integer.
    *      grade is a non-empty string.
    *
    * @post The type, year, grade, and count data members are initialized with the input values.
    */
   Item(char type, int year, string grade);

   /**
    * @brief Returns a string containing the information about the item.
    * This method will be overridden in the derived classes (Coin, Comic, SportsCard).
    * This implementation of the method simply returns an empty string.
    * @pre None.
    *
    * @post A string containing the information about the item is returned.
    *
    * @return A string containing the information about the item.
    */
   virtual std::string getInfo();

   /**
    * @brief Compares two items based on their sorting criteria.
    *
    * @pre This method is overridden in the child classes (Coin, Comic, SportsCard).
    *
    * @post True is returned if this item should come before the other item in the sorting order,
    *       false otherwise.
    *
    * @param other The other item to compare to.
    *
    * @return -1 if this item should come before the other item in the sorting order, 1 otherwise.
    */
   virtual int compare(Item* other);

   /**
    * @brief Sets the count of this item to the given value.
    *
    * @pre count is a non-negative integer.
    *
    * @post The count data member of this item is set to the given value.
    *
    * @param count The new count value for this item.
    */
   void setCount(int count);

   char type;
   int count;
   int year;

protected:
   
   string grade;
   
};
