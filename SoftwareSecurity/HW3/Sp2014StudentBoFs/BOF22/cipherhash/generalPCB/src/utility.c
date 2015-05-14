/*
 * utility.c
 *
 *  Created on: Feb 15, 2015
 *      Author: hilberttaylor
 */

//
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "utility.h"

void PressEnterToContinue(void)
{
	printf ( "Press [Enter] to continue . . ." );
	fflush ( stdout );
	getchar();
}
void myflush ( FILE *in )
{
  int ch;
  printf ( "\nPress [Enter] to continue . . ." );
  do
    ch = fgetc ( in );
  while ( ch != EOF && ch != '\n' );

  clearerr ( in );
}

int clean_stdin(void)
{
	while (getchar()!='\n');
	return 1;
}
char* readInputStr()
{
	int count = 0;
	static char rowStr[256];
	char c;

	do
	{
		printf("\nEnter less than 256 characters : ");

	} while ((scanf("%s%c", &rowStr, &c)!=2 || c!='\n') && clean_stdin());

	char *y;
	y = (char*) &rowStr;
	return y;
}

int readInputInt ()
{
	int count = 0;
	int rowsInt =0;
	char c;

	do
	{
		printf("\nEnter an integer : ");

	} while ((scanf("%d%c", &rowsInt, &c)!=2 || c!='\n') && clean_stdin());

	return rowsInt;
}

char * curentSysTime(void)
{
	time_t mytime;
	 struct tm *mylocltime;
	/* Get the current time. */
	mytime = time (NULL);
	/* Convert it to local time representation. */
	mylocltime = localtime (&mytime);
	/* Return the date and time in the standard format. */
	char *mystr_time = asctime (mylocltime);
	return mystr_time;
}

void stringCopy(char str1[],char str2[]){
   int i=0;

   while(str1[i]!='\0'){
        str2[i] = str1[i];
        i++;
   }

   str2[i]='\0';
}
