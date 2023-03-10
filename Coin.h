#pragma once

#include <string>
#include <iostream>

#include "Item.h"

class Coin : public Item {
public:
   Coin(int year, int grade, std::string coinType);

   ~Coin();

   std::string getInfo() override;
   
   bool compare(Item* other) override;

   static void sort(Coin* coins, int numCoins);

private:
   char type = 'M';
   std::string coinType;
};

