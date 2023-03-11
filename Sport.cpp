#include "Sport.h"

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
Sport::Sport(int year, string grade, string player, string manufacturer)
   : Item('S', year, grade), player(player), manufacturer(manufacturer) {}

/**
 * @brief Returns a string representation of the sport item, including player name, year, grade, and manufacturer.
 *
 * @pre None.
 *
 * @post A string representation of the sport item is returned.
 *
 * @return A string representation of the sport item, including player name, year, grade, and manufacturer.
 */
std::string Sport::getInfo() {
   return "Sport: " + player + " (" + std::to_string(year) + "), Grade: " + grade + ", Manufacturer: " + manufacturer;
}

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
int Sport::compare(Item* other) {
   Sport* otherSport = dynamic_cast<Sport*>(other);
   if (otherSport == nullptr) {
      return -1;
   }

   if (player < otherSport->player)
      return -1;
   if (player > otherSport->player)
      return 1;

   if (year < otherSport->year)
      return -1;
   if (year > otherSport->year)
      return 1;

   if (manufacturer < otherSport->manufacturer)
      return -1;
   if (manufacturer > otherSport->manufacturer)
      return 1;

   if (grade < otherSport->grade)
      return -1;
   if (grade > otherSport->grade)
      return 1;

   return 0;
}
