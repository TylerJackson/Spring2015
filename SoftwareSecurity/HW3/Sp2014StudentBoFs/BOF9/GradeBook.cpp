#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int NUM_USERS = 4;
const int SIZE_STRINGS = 8;
const int NUM_GRADES = 4;

bool comparePassword (char enteredPassword[SIZE_STRINGS] , char password[SIZE_STRINGS]);
int findUser(string passedUserName, char passedUserNames[NUM_USERS][SIZE_STRINGS]);
char isATeacher(int position, char isTeacherFlags[NUM_USERS]);
void showGrades(char grades[NUM_GRADES], char subjects[NUM_GRADES][SIZE_STRINGS]);
void showAllGrades(char name[], char grades[],char subjects[][SIZE_STRINGS]);

int main() {


	char grades[NUM_GRADES][SIZE_STRINGS]
			{
					{'A','B','C','A','\0'},
					{'A','A','A','A','\0'},
					{'A','B','C','A','\0'},
					{'D','F','F','F','\0'}
			};

	char isTeacherFlags[5] = {'Y','N','N','N','\0'};

	char password[8];

	string enteredPassword;

	char passwords[NUM_USERS][SIZE_STRINGS] =
		{
				{'B','o','b','b','y', '\0'},
				{'A','l','i','c','e', '1', '\0'},
				{'T','r','u','d','y', '2', '\0'},
				{'C','r','a','i','g', '3', '\0'}
		};

	bool isValidUser = false;
	int userOffset = -1;
	char subjects[NUM_GRADES][SIZE_STRINGS] =
		{
					{'H','i','s','t','o','r','y','\0'},
					{'B','i','l','o','g','y','\0'},
					{'M','a','t','h', '\0'},
					{'E','n','g','l','i','s','h','\0'}
	    };


	char userNames[NUM_USERS][SIZE_STRINGS] =
		{
				{'B','o','b','\0'},
				{'A','l','i','c','e', '\0'},
			    {'T','r','u','d','y', '\0'},
			    {'C','r','a','i','g', '\0'}
	    };


	string inputName;
    while(true) {

		cout << "Please Enter Your User Name: ";
		cin >> inputName;
		if (inputName.length() > 8){
			cout << "Name length was greater than 8 need to enter a new user name. " << endl;
			userOffset = -1;
		} else {
		   userOffset = findUser(inputName,userNames);
		}

		if (userOffset != -1){

		   cout << "Hello: " << inputName << endl;
		   cout << "Please Enter Password: ";
		   cin>> enteredPassword;
		   if (enteredPassword.length() > 8){
			   isValidUser = false;
		   } else {
			   strcpy(password,enteredPassword.c_str());
			   isValidUser = comparePassword(password,passwords[userOffset]);
		   }

		   if (isValidUser){
			   char isTeacherFlag = isATeacher(userOffset,isTeacherFlags);
			   if (isTeacherFlag == 'Y') {
				   for(int i = 0 ; i< NUM_USERS ; i++){
					   showAllGrades(userNames[i],grades[i],subjects);
				   	}

			   }  else {
   			       showGrades(grades[userOffset],subjects);
			   }
		   } else {
			   printf("Invalid Password of ");
			   printf(password);
			   printf(" was entered, please reenter the password. ");
			   cout << endl;
		   }
		 } else {
		   printf(inputName.c_str());
		   printf(" was an invalid User Name entered, please enter a valid User Name\n" );
		 }
    }

	return 0;

}

int findUser(string passedUserName, char passedUserNames[][SIZE_STRINGS])
{
	string userString(passedUserName);
	for(int i = 0 ; i< NUM_USERS ; i++){
		string pUserString(passedUserNames[i]);
		if (userString==pUserString ){
			return i;
		}
	}
	return -1;
}


bool comparePassword (char enteredPassword[] , char password[] )
{
	string p1(enteredPassword);
	string p2(password);
	return p1 == p2;
}

char isATeacher (int position, char isTeacherPermissions[])
{
  return isTeacherPermissions[position];

}

void showGrades(char grades[],char subjects[][SIZE_STRINGS]){

    cout << " " << endl;
	cout << "Here are your grades:" << endl;
	for(int i = 0 ; i< NUM_GRADES ; i++){
		  char subjectGrade = grades[i];

		  string subject(subjects[i]);
		  string outputString;
		  outputString =  subject + " grade was a(n) " + subjectGrade;

		  cout << " " << endl;
		  cout << outputString << endl;
    }
}

void showAllGrades(char name[], char grades[],char subjects[][SIZE_STRINGS]){

    cout << " " << endl;

    cout << "Here are the grades for the user :" << name << endl;
	for(int i = 0 ; i< NUM_GRADES ; i++){

		  char subjectGrade = grades[i];

		  string subject(subjects[i]);
		  string outputString;
		  outputString =  subject + " grade was a(n) " + subjectGrade;

		  cout << " " << endl;
		  cout << outputString << endl;
    }
}
