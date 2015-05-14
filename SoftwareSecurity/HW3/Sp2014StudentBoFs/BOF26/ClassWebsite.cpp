/*
Name:	Class Website
Author:	Tyler Jackson
Description: This program has two paths, one for a student and one for a professor.  
	    A student's page has a little info about the class, and a professor's page 
	    has information about the students.
Date: 3/18/2015
Assignment 2: Buffer Overflows
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

void loginTeacher();
void loginStudent();

int main ()
{
	while(true)
	{
		cout<<"Hello and Welcome to the Class's Website."<<endl<<endl<<endl;
		cout<<"If you would like to login as a student please type S" <<endl << "Otherwise if you want to login as Professor Estes, enter P for Professor." <<endl;
	
		char studentOrTeacher;
		bool validInput = false;
		bool isTeacher = false;
		studentOrTeacher = getchar();
		while(cin.get() != '\n');
		//cin.ignore();
		while(!validInput){
			if(studentOrTeacher == 'P')
			{
				validInput = true;
				isTeacher = true;
			}else if(studentOrTeacher == 'S'){
				validInput = true;
			}else{
				cout<<"S or P... That wasn't an S or a P"<<endl;
				studentOrTeacher = getchar();
				while(cin.get() != '\n');
			}
		}
		if(isTeacher)
		{
			loginTeacher();	
		}else
		{
			loginStudent();
		}
	}
	
return 0;	

}

void loginTeacher()
{

	string middleName;
	cout<<"Hello Professor, please type in your middle name: ";
	cin>>middleName;

	int numberOfTries = 0;
	bool validInput = false;

	while(!validInput && numberOfTries < 3)
	{
		if(middleName == "Muriel")
		{
			validInput = true;
		}else{
			numberOfTries++;
			if(numberOfTries < 3) 
			{
				cout<<"Incorrect, you will have 3 total tries..."<<endl;
				cin>>middleName;
			}else
			{
				cout<<"Sorry, you have failed to authenticate..."<<endl<<endl<<endl<<endl;
				return;
			}
		}
	}
	
	cout << "Thank you, now enter your shoe size: ";
	string shoeSize;
	cin>>shoeSize;

	validInput = false;
	numberOfTries = 0;

	while(!validInput && numberOfTries < 3)
	{
		if(shoeSize == "11")
		{
			validInput = true;
		}else
		{
			numberOfTries++;
			if(numberOfTries < 3) 
			{
				cout<<"Incorrect, you will have 3 total tries.."<<endl;
				cin>>shoeSize;
			}else
			{	
				cout<<"Sorry, you have failed to authenticate..."<<endl<<endl<<endl<<endl;
				return;
			}
		}	
	}
	cout<<"Thank you, now enter your favorite cocktail: ";
	cin.ignore();
	string favoriteCocktail;
	getline(cin,favoriteCocktail);
	
	validInput = false;
	numberOfTries = 0;
	
	while(!validInput && numberOfTries < 3)
	{
		if(favoriteCocktail == "Whiskey and Coke")
		{
			validInput = true;
		}else
		{
			numberOfTries++;
			if(numberOfTries < 3) 
			{
				cout<<"Incorrect, you will have 3 total tries.."<<endl;
				getline(cin,favoriteCocktail);
			}else
			{
				cout<<"Sorry, you have failed to authenticate..."<<endl<<endl<<endl<<endl;

				cout<<"Press Enter to return to the home screen"<<endl;
				return;
			}
		}
	}
	cout << "Thank you. For our last form of authentication, what was your biggest fear growing up: ";
	string biggestFear;
	cin>>biggestFear;

	validInput = false;
	numberOfTries = 0;
	
	while(!validInput && numberOfTries < 3)
	{
		if(biggestFear == "Clowns")
		{
			validInput = true;	
		}else
		{
			numberOfTries++;
			if(numberOfTries < 3) 
			{
				cout<<"Incorrect, you will have 3 total tries.."<<endl;
				cin>>biggestFear;
			}else
			{
				cout<<"Sorry, you have failed to authenticate..."<<endl<<endl<<endl<<endl;
				return;
			}
		}
	}	
	int answer;
	cout << "Almost there... to prove you are not a robot, solve this simple problem: 11 ploos thray mines tew"<<endl;
	cin>>answer;

	validInput = false;
	numberOfTries = 0;

	while(!validInput && numberOfTries < 3)
	{
		if(answer == 12)
		{	
			validInput = true;
			cout << "--------------------------------------------------------------"<<endl<<endl;
			cout<<"Welcome Professor Estes.  Here are all the grades..."<<endl<<endl;
			char filename [11] = "grades.txt";
			ifstream f (filename);
			if(f.is_open()){
				string temp;

				while(getline(f,temp))
				{
					cout << temp << endl;
				}
				f.close();
				cout << "You will now be logged out.." << endl;
				cout << "--------------------------------------------------------"<<endl;	
			}
		}else
		{
			numberOfTries++;
			if(numberOfTries < 3) 
			{
				cout<<"Incorrect, you will have 3 total tries.."<<endl;
				cin>>answer;
			}else
			{
				cout<<"Sorry, you have failed to authenticate..."<<endl<<endl<<endl<<endl;
				return;
			}
		}
	}		
}

void loginStudent()
{
	char filename[19] = "welcomeStudent.txt";
	char name[25];

	printf("What is your first and last name?\n");


	

	//get first and last name
	int offset = 0;
	char answer;
	while( (answer = getchar()) != '\n')
	{
		name[offset]=answer;
		offset++;
	}

	name[offset] = '\0';
	cout << endl << endl << "Almost there... to prove you are not a robot, solve this simple problem: 11 ploos thray mines tew"<<endl;
	string recaptcha;

	getline(cin,recaptcha);

	//double check not a robot and then display welcome text
	//from file
	ifstream f (filename);
	if(f.is_open() && recaptcha == "12"){
		string temp;
		cout << "-------------------------------------------------------"<<endl;
		cout << endl<<endl<<"Hello " << name << ".  You have successfully logged in."<<endl << endl;
		while(getline(f,temp))
		{
			cout << temp << endl;
		}
		cout << "You will now be logged out.." << endl;
		f.close();
	//loginStudent();
	}else
	{
		cout<<"Wrong, you must be a robot!" << endl<<endl;
		cout << "You will now be sent back to the homescreen.."<<endl;
	}

		cout << "--------------------------------------------------------"<<endl;	
}
