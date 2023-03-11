#pragma once

#include "Item.h"

class Coin : public Item {
public:
   Coin(int year, string grade, string coinType);

   ~Coin();

   std::string getInfo() override;
   
   int compare(Item* other) override;


private:
   char type = 'M';
   std::string coinType;
};

