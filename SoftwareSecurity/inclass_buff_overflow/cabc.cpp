#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

float FreeCable()
{
        float i = 0;
        return i;
}

float EmptyPockets(char *acctBuf, int packageNo)
{
        /*char sub[8] = "1337";
        if(strcmp(strcat(sub, acctBuf), "1337h4x0r") != 0)
        {
                return 79.99;
        }
        else return 10;*/
	switch (packageNo)
		{
		case 100:
			return 49.99;
			break;
		case 200:
			return 59.99;
			break;
		case 300:
			return 69.99;
			break;
		default:
			cerr << "stop trying to jack with my program\n";
			exit(1);
		}
		return 100;	
}

int main ()
{
        char actNum[16];
	puts("Enter your activation number:");
	fgets(actNum, 16, stdin);
	puts("Enter package: Top100 [100], Top200 [200], Top300 [300]");
	int packageNo = 0;
	char packageStr[4];
	fgets(packageStr, 4, stdin);
	packageNo = atoi(packageStr);
	if(packageNo == 0)
	{
  		cerr << "stop trying to jack with my program\n";
		exit(1);
	}
        //float balance = EmptyPockets(actNum, packageNo);
        puts("Connecting you to your cable provider...\n");
        sleep(1);
	puts("Checking your activation token...\n");
	ifstream licFile;
	licFile.open("activation.lic", ifstream::in);
	char licCode[8];
        float balance = EmptyPockets(actNum, packageNo);
	licFile >> licCode;
	unsigned int validLic = 0;
	for(int i=0; i<8; i++)
	{
		validLic += licCode[i];
	}
	if(validLic == 800)
	{ 			
        	printf("Your monthly fee is: $%2.2f \n", balance);
		return 0;
	}
	else
	{
		printf("Activation code is invalid and stop jacking with it!\n");
	}
}
