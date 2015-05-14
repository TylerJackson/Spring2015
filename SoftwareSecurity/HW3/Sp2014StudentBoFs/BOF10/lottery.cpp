//Gladman K. Dibi
//March 16, 2015
//Lotery.cpp


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

void Winner(char num1[3],char num2[3], char num3[3], char flag)
{

char wnum1[3] = "23";
char wnum2[3] = "50";
char wnum3[3] = "50";
int comp1;
int comp2;
int comp3;

comp1 = strncmp(wnum1,num1,2);
comp2 = strncmp(wnum2,num2,2);
comp3 = strncmp(wnum3,num3,2);
  if (comp1 == 0 && comp2 == 0 && comp3 == 0)	
  {	 
	  flag = 't';
  }
  if(flag == 't'){
       	  printf ("WOW YOU BROKE MY BANK.  Collect your money and run!\n");
  }
  else
  {
       	  printf ("Sorry you are not a winner today\n");
  }
  
}

int main ()
{
char num1[3] = {'\0'};
char num2[3] = {'\0'};
char num3[3] = {'\0'};
char flag = 'f';

printf ("\nToday could be your lucky day but it probably won't be\n");
printf ("Guess the three lucky numbers and win $1,000,000\n");
printf ("Lets begin. Good luck!\n \n \n");

printf ("Enter your first number and press enter:\n");
scanf ("%s", &num1);

printf ("Enter your second number and press enter:\n");
scanf ("%s", &num2);

printf ("Enter your third number, cross your fingers, and press enter:\n");
scanf ("%s", &num3);

Winner(num1,num2,num3,flag);

}
