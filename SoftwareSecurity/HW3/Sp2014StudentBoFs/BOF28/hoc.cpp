#include <stdio.h>
#include <string.h>
#include <ctime>
#include <iostream>

using namespace std;

int validReleaseDate(int total, int releaseDate)
{
	int totals = total; 

	char validDate = 'F';
	char seasonNumber[2];
	
	scanf("%s", seasonNumber);

	if(totals == releaseDate)
	{
		validDate = 'T';
	}

	if(!strcmp(seasonNumber,"1") || !strcmp(seasonNumber,"2") || !strcmp(seasonNumber,"3"))
		printf("You are watching season %s\n", seasonNumber);
	else
		printf("Sorry that is not valid input or that season is not available yet.\n");

	return (validDate == 'T');
}

int main()
{
	//Get the current local time with ctime[C++] - runnable
	time_t currentTime;
	struct tm *localTime;
	time(&currentTime);
	localTime = localtime(&currentTime);

	int month = localTime->tm_mon + 1;
	int day = localTime->tm_mday;
	int year = localTime->tm_year + 1900;

	//std::cout << "The current date is: " << month << "/" << day << "/" << year << std::endl;

	//add up todays date
	int total = month + day + year;

	//total of release date 12/28/2016
	int releaseDate = 2056; 


	printf("Enter a House of Cards Season (1-3): \n");
	
	if(validReleaseDate(total, releaseDate))
		puts("You are watching the new season of House of Cards!!");
	

}