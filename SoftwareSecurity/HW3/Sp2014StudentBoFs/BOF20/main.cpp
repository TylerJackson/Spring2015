/* 
 * Author: Jim Lomeo
 * CSE 5359 Lab 2
 *
 * Created on March 5, 2015, 8:51 AM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
 * 
 */

void firstClassPrompt(int);

void reservationPrompt(){
    string depCity;
    string arrCity;
    
    cout << "Welcome to VulnAir's Reservation System" << endl;
    
    cout << "Where will you be departing from? (3 Letter Airport Code)" << endl;
    cin >> depCity;
    
    cout << "Where are you going? (3 Letter Airport Code)" << endl;
    cin >> arrCity;
    
    srand(time(NULL));
    int economyPrice = rand() % 203 + 97;
    cout << "The price of a ticket from " <<  depCity << " to " << arrCity << " in Economy Class will be $" << economyPrice << endl;
    firstClassPrompt(economyPrice);
    
}

void firstClassPrompt(int passedEcoPrice){
    char upgradeMoneyAmt[4] = "500";
    char upgradeAnswer[4] = {};
    cout << "Would you like to upgrade to First Class? Yes/No" << endl;
    cin >> upgradeAnswer;
    
    if(strcmp(upgradeAnswer, "No")){
		//they chose to upgrade
        int upAmtInt = atoi(upgradeMoneyAmt);
        cout << "Thank you for your upgrade purchase. Your new total is:" << endl;
        cout << "UPGRADE COST: $" << upAmtInt << endl;
        cout << "BASE AIRFARE COST: $" << passedEcoPrice << endl;
        cout << "TOTAL TO BE INVOICED: $" << upAmtInt + passedEcoPrice << endl;        
        
        
    }
    
    else{
	//no upgrade chosen
        cout << "Thank you for your airfare purchase. Your total is:" << endl;
        cout << "TOTAL TO BE INVOICED: $" << passedEcoPrice << endl;	
        
        
    }
    
    
    
}

int main(int argc, char** argv) {
    
    reservationPrompt();
    
    return 0;
}

