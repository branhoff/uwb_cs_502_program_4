// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include "Inventory.h"

int main() {
   Inventory inventory;
   inventory.readInventory("hw4inventory.txt");
   inventory.readCustomer("hw4customers.txt");
   inventory.parseCommands("hw4commands.txt");
   //Coin coins[numCoins] = {
   //    Coin(1909, 65, "Lincoln Cent"),
   //    Coin(1932, 68, "Washington Quarter"),
   //    Coin(1889, 60, "Morgan Dollar")
   //};

   //for (int i = 0; i < numCoins; i++) {
   //   std::cout << coins[i].getInfo() << std::endl;
   //}

   //Coin::sort(coins, numCoins);

   //for (int i = 0; i < numCoins; i++) {
   //   std::cout << coins[i].getInfo() << std::endl;
   //}


   //std::string inventoryFile = "hw4inventory.txt";
   //std::ifstream input(inventoryFile);

   //while (invStream.peek() != EOF) {
   //   string fileInput;
   //   getline(inventoryStream, fileInput);
   //   // Do something to parse the line of input here
   //}


   return 0;
}
