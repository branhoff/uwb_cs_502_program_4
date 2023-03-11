#include "Item.h"

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
Item::Item(char type, int year, string grade) {   
   this->type = type;
   this->year = year;
   this->grade = grade;
   this->count = 0;
}

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
std::string Item::getInfo() {
   return "";
}

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

int Item::compare(Item* other) {
   if (this->grade < other->grade) {
      return -1;
   }
   else {
      return 1;
   }
}

void Item::setCount(int count)
{
   this->count = count;
}
