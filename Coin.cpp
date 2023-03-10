#include "Coin.h"

Coin::Coin(int year, int grade, std::string coinType) : Item('M', year, grade), coinType(coinType) {}

Coin::~Coin() {}

std::string Coin::getInfo() {
   return "Coin: " + coinType + " (" + std::to_string(year) + "), Grade: " + std::to_string(grade);
}

bool Coin::compare(Item* other) {
   Coin* otherCoin = dynamic_cast<Coin*>(other);
   if (otherCoin == nullptr || coinType < otherCoin->coinType) {
      return true;
   }
   if (coinType == otherCoin->coinType) {
      if (year < otherCoin->year) {
         return true;
      }
      if (year == otherCoin->year) {
         if (grade < otherCoin->grade) {
            return true;
         }
      }
   }
   return false;
}

void Coin::sort(Coin* coins, int numCoins) {
   for (int i = 0; i < numCoins - 1; i++) {
      for (int j = i + 1; j < numCoins; j++) {
         if (coins[i].compare(&coins[j])) {
            Coin temp = coins[i];
            coins[i] = coins[j];
            coins[j] = temp;
         }
      }
   }
}