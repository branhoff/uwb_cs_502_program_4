#pragma once

#include "Item.h"

class Coin : public Item {
public:
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
   Coin(int year, string grade, string coinType);

   ~Coin();
   /**
    * @brief Returns a string representation of the coin, including its coin type, year, and grade.
    *
    * @pre None.
    *
    * @post A string representation of the coin, including its coin type, year, and grade, is returned.
    *
    * @return A string representation of the coin, including its coin type, year, and grade.
    */
   std::string getInfo() override;
   
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
   int compare(Item* other) override;


private:
   char type = 'M';
   std::string coinType;
};

