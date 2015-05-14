#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

int drinksPurchased = 0;

void buyDrinkOnTheHouse(){
   drinksPurchased++;
}

void checkForQuit(){
   char quit[4];
   puts("Are you sure you want to quit? [yes/no]:");
   cin >> quit;
   if (strcmp(quit,"yes") == 0)
      puts("OK, byeeeeee.");
   else
      puts("Too late. See you next time.");
}

int main() {

   int balance = 40.00;

   puts("Welcome to STARBUCKS.\n");

   int action = 0;

   printf("Current card balance: $%d\n", balance);
   printf("You have purchased %d drinks.\n\n", drinksPurchased);

   puts("1. Buy a drink ($5)");
   puts("2. EXIT starbucks");
   puts("Select an action: ");

   char actionStr[4];
   fgets(actionStr, 4, stdin);
      action = atoi(actionStr);

   if (action == 0 || action > 2) {
      cerr << "Invalid menu choice." << endl;
      exit(1);
   }

   else if (action == 1) {
      drinksPurchased++;
      balance -= 5;
   }

   else if (action == 2) {
      checkForQuit();
   }

   printf("\nYour final balance is $%d\n", balance);
   printf("You purchased %d drink(s)\n", drinksPurchased);

   return 0;
}
