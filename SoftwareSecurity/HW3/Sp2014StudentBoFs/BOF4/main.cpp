/*
 * Jeffrey Artigues
 * CSE 7359
 * Lab 2
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * 
 */
int verifyLogin(){
    char adminLogin[16] = "StanTheMan";
    char inputUsername[16];
    char adminPassword[16] = "Excelsior";
    char inputPassword[16];
    cout << "Username: ";
    gets(inputUsername);
    cout << "Password: ";
    gets(inputPassword);
    if (strcmp(adminLogin, inputUsername)==0 && strcmp(adminPassword, inputPassword)==0){
        return 1;
    }
    cout << "Login failed. You have one chance to re-enter your information: \n";
    cout << "Username: ";
    gets(inputUsername);
    cout << "Password: ";
    gets(inputPassword);
    if (strcmp(adminLogin, inputUsername)==0 && strcmp(adminPassword, inputPassword)==0){
        return 1;
    }
    return 0;
}

void loginSuccess(){
    cout << "Login Succeeded\n";
}
int main(int argc, char** argv) {
    cout << "Welcome to Super Secure Login. Enter your login credentials: \n";
    int result = verifyLogin();
    if (result == 1){
        loginSuccess();
    }
    else if (result == 0){
        cout << "Access Denied";
    }
    return 0;
}