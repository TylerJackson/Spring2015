#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char* user;
int ccnum;
int PIN;



int getCCNum(){
	cout << "Please enter card number" << endl;
	cin >> ccnum;
	return ccnum;
}

int getPIN(){
	cout << "Please enter PIN" << endl;
	cin >> PIN;
	return PIN;
}

void startStandard(){
	double amount = 0;
	ccnum = getCCNum();
	PIN = getPIN();
	cout << "Please enter how much you would like to withdraw" << " (this ATM sucks so you cannot deposit.  Deal with it.)" << endl;
	cin >> amount;
	cout << "Here is $" << amount << " now go away please." << endl;
}


void openATM()
{
	cout << "Aaaaaaaand open!" << endl;
}

void startMantainance(){
	char password[20];
	int valid = 0;
	cout << "Lets see what you got Mr. Hacker.  Ok fine, Mr. or Mrs. Hacker" << endl << " enter your password:" << endl;
	cin >> password;
	if(strcmp(password, "please"))
	{
		cout << "HAHAHAHAHA you got it wrong, the police have been alerted. HAHAHAH" << endl;
	}
	else
	{
		cout << "Well look at you, smarty, you got it.  slowww clapp" << endl;
		valid = 1;
	}

	if(valid)
	{
		openATM();
	}
}



int main( int argc, const char* argv[] ){
	int mode = 0;

	cout << "Please select mode:" << endl << "1) standard mode" << endl << "2) mantainance mode" << endl;
	cin  >> mode;

	switch(mode){
		case 1: startStandard(); break;
		case 2: startMantainance(); break;
		default: cout << "invalid choice, try again"; break;
	}

}