#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int searchForUser(char* username, char* users[500]){
	for(int i = 0; i < 500; i++){
		if(strcmp(users[i], username) == 0){
			return i;
		}
	}

	return -1;
}

int checkPass(char* password, int loc, char* passwords[500]){
	if(strcmp(password, passwords[loc]) == 0){
		return 1;
	}

	return 0;
}

void printBallance(int acct, int ballances[500]){
	printf("$%i\n\n", ballances[acct]);
}

void withdrawMoney(int acct, int ballances[500]){
	char amt[80];
	int iamt;

	printf("How much would you like to withdraw? \n(This system will round down to the nearest dollar.)\n");
	printf("--> ");

	scanf("%s", amt);
	iamt = atoi(amt);
	

	if((iamt < 0) || (iamt > ballances[acct])){
		printf("Cannot withdraw that amount.\n\n");
	} else {
		ballances[acct] = ballances[acct] - iamt;
		printf("Successful withdraw!\n\n");
	}
}

int main(void){
	char input[20];
	int acct = 0;
	char* users[500];
	char* passwords[500];
	int ballances[500];
	char uname[80];
	char pass[80];
	srand(time(NULL));

	for(int i = 0; i < 80; i++){
		uname[i] ='\0';
		pass[i] = '\0';
	}
	
	char num[4];
	for(int i = 0; i < 500; i++){
		sprintf(num, "%d", (i+1));
		users[i] = new char[10];

		for(int j = 0; j < 10; j++){
			users[i][j] = '\0';
		}

		strcpy(users[i], "user");
		strcat(users[i], num);

		sprintf(num, "%d", (rand() % 999));
		passwords[i] = num;
		ballances[i] = 5000 + i;
	}

	passwords[299] = "password";

	while(true){
		printf("Enter Username: ");
		scanf("%s", uname);
		printf("Enter Password: ");
		scanf("%s", pass);

		acct = searchForUser(uname, users);
		if(acct == -1){
			printf("Username or Password Incorrect");
			printf("\n\n");
			continue;
		}
		if(checkPass(pass, acct, passwords) != 1){
			printf("Username or Password Incorrect");
			printf("\n\n");
			continue;
		}

		printf("Successfully Logged In");
		printf("\n\n");
		break;
	}

	while(true){
		printf("Welcome ");
		printf(users[acct]);
		printf(". ");
		printf("Please select a menu item.\n");
		printf("\t1. Check Ballance\n");
		printf("\t2. Withdraw Money\n");
		printf("\t3. Logout\n");
		printf("--> ");
		scanf("%s", input);

		if(strcmp("1", input) == 0){
			printBallance(acct, ballances);
		} else if(strcmp("2", input) == 0){
			withdrawMoney(acct, ballances);
		} else if(strcmp("3", input) == 0){
			printf("Thank you! Have a nice day!\n");
			break;
		} else {
			printf("That is not a valid option. Please try again.\n\n");
		}
	}
}