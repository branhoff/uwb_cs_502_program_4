#include "Sport.h"

Sport::Sport(int year, string grade, string player, string manufacturer)
   : Item('S', year, grade), player(player), manufacturer(manufacturer) {}

std::string Sport::getInfo() {
   return "Sport: " + player + " (" + std::to_string(year) + "), Grade: " + grade + ", Manufacturer: " + manufacturer;
}

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
