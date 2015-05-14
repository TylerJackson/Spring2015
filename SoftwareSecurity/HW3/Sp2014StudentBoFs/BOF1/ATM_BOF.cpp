#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

bool validate();

int main() {
    bool validatingPin = false;
    char amount[6];
    char user[20];
    bzero (amount, 0);    

    printf("\n\n                         -- Welcome to Dallas Bank. --\n");
    printf("Please enter the username: \n");
    printf("Username: ");
 
    fgets(user, 18, stdin);
    printf("Please enter the pin to continue: \n");
    validatingPin = validate();
    
	printf("Enter amount$: \n");
	fgets(amount, 10, stdin);

    if (validatingPin == true)
    	cout << "The amount $" << amount << " has been withdrawn." << endl;
   else
        printf("Pin number is invalid. Please re-enter your pin numnber\n");
    return 0;
}

bool validate() {
    char pin[4];
    printf("Pin Number: ");
    fgets(pin, 4, stdin);
    int valid = strcmp(pin, "9999");
	return (valid == 0) ? true : false;
}
