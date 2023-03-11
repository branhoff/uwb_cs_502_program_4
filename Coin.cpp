#include "Coin.h"

Coin::Coin(int year, string grade, std::string coinType) : Item('M', year, grade), coinType(coinType) {}

Coin::~Coin() {}

std::string Coin::getInfo() {
   return "Coin: " + coinType + " (" + std::to_string(year) + "), Grade: " + grade;
}

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