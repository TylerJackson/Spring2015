#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
const static int user_ssn_size = 16;
const string fileName = "account.dat";
string readAccount (string fileName);
int main() {

	char SSN[user_ssn_size] = "551342239";
	char userSSN[user_ssn_size];
	bool extraLines;
	bool loggedIn;

	loggedIn=false;
	extraLines = true;
	std::cout<<"Please enter your social security number: ";

	while(extraLines) {
		fgets(userSSN, user_ssn_size, stdin);
		for(int i = 0; i < user_ssn_size; i++) {
			if (userSSN[i] == '\n' || userSSN[i] == '\r') {
				userSSN[i] = '\0';
				extraLines = false;
			}
		}

		if(extraLines)
			userSSN[user_ssn_size] = '\0';
	}

	
	//if the userSSN matches the password, log the user in
	if(strncmp(userSSN, SSN, 8) == 0) {
		std::cout<<"Login successful!\n";
		loggedIn = true;
		cout<<readAccount(fileName);
	} else
		std::cout<<"Login failed.\nPlease try again.\n";
	return 0;
}

string readAccount ( string fileName)
{
 std::ifstream file("account.dat");
 std::string str;
 std::string file_contents;
 while (std::getline(file, str))
   {
    file_contents += str;
    file_contents.push_back('\n');
   }  
 return file_contents;
}
