#pragma once

// Item class:
//   Represents a collectible item, with data members for type, year, and grade.
//   Includes the following methods:
//      Item - constructor that initializes the data members
//      getInfo - virtual function to get information about the item
//   Assumptions:
//      - The input to the constructor should be valid, with a valid item type, a positive year, and a non-empty grade string.
//      - The virtual function getInfo will be overridden in the derived classes (Coin, Comic, SportsCard).
//--------------------------------------------------------------------

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

   void setCount(int count);

   char type;
   int count;
   int year;

protected:
   
   
   string grade;
   

   
};
