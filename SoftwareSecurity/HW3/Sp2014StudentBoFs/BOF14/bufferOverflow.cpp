//
//  bufferOverflow.cpp
//  
//
//  Created by Roberto Hernandez on 3/7/15.
//  Copyright (c) 2015 Roberto Hernandez. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    int authentication = 1;

    cout << "Welcome To Arkham Bank!\n";
    cout << "Create An Account!\n\n";
    
    cout << "Please Enter Your First Name:\n";
    char name[16];
    cin >> name;
    if(strlen(name) > 15)
    {
        cout << "Oops your name is too long!\n";
        system("pause");
        return 0;
    }
    else
    {
        cout << "Thanks " << name << "!\n\n";
    }
    
    cout << "Enter a PIN no longer than 3 numbers:\n";
    char password[4];
    cin >> password;
    if(strlen(password) > 3)
    {
        cout << "Oops your password is too long!\n";
        system("pause");
        return 0;
    }
    else
    {
        cout << "\nYour Account has been successfully made!\n\n";
    }
    
    cout << "\nLog into your account!\n";
    
    cout << "Enter name:";
    char logName[16];
    cin >> logName;
    
    cout << "PIN:";
    char logPass[4];
    cin >> logPass;
    
    if(strcmp(logName, name) == 0 && strcmp(logPass, password) == 0)
    {
        authentication = 1;
    }

    if(authentication == 1)
    {
        cout << "Welcome to your session " << name << "!\n";
        cout << "Your balance is $1,000,000\n";
        cout << "How much do you want to withdraw?\n";
        int withdraw;
        cin >> withdraw;
        
        if(withdraw > 1000000)
        {
            cout << "You don't have that much money in your balance!";
            system("pause");
            return 0;
        }
        else
        {
            cout << "Your balance is now $" << 1000000-withdraw << "\n";
        }
    }
    else
    {
        cout << "Wrong username and password combination try again\n";
    }
    
    return 0;
}