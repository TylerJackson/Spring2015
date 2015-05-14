#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int winCount = 0;
int loseCount = 0;

// Malicious code to always win this game!
you_always_win()
		{
                printf("\n**************************************\nI'm sorry! But, no matter what, I will always Win! Ha Ha Ha!\n");
                printf("***************************************");
                printf("\nHuman Wins:100 times more than what the computer wins \tComputer Wins: :( :( :(\n");
                exit(0);
        }

/* This method is used to validate the flag and
 display an appropriate message on the screen*/
int validateFlag(char flag, int winC, int loseC)
        {
                if(flag == 'W')
                {
                        printf("\nYou Win!\n");
                        winC = winCount++;
                        printf("\nHuman Wins: %i\tComputer Wins: %i", winCount, loseCount);
                        return winC;
                }
 
                else if(flag == 'L')
                {
                        printf("\nYou Lose!\n");
                        loseC = loseCount++;
                        printf("\nHuman Wins: %i\tComputer Wins: %i", winCount, loseCount);
                        return loseC;
                }
 
                else if(flag == 'T')
                {
                        printf("\nIt's a Tie!\n");
                        printf("\nHuman Wins: %i\tComputer Wins: %i", winCount, loseCount);
                }
       }

/* Main method that gets the user input,
generates a computer's input and sets
the flag*/
main()
{
        char selection[8] = {'\0'};
        char flag = 'T';   // W - Won, T- Tie , L- Lost
        char play = 'y';
        int iRandom = 0;
        int iSelection = 0;
        srand(time(0));
       
        printf("\n*********************************************************\n");
        printf("Welcome to Rock-Paper-Scissors Game!");
        printf("\nHuman Wins: %i\tComputer Wins: %i", winCount, loseCount);
        printf("\n*********************************************************");
        printf("\nDo you want to play Rock-Paper-Scissors? (y/n) ");
        scanf(" %c", &play);
        
        if(play == 'n')
        {
                exit(0);
        }
 
        do{
                 iRandom = (rand() % 3) + 1;
                 printf("I hope you know the rules. So, Lets begin !!! 1..2..3..! \n");
                 printf("\n\tRock, Paper, Scissors!\n");
                 printf("1.\tRock\n");
                 printf("2.\tPaper\n");
                 printf("3.\tScissors\n");
                 printf("\nSelect your option: ");
                 scanf("%s", selection);
                 iSelection  =  atoi(selection);
       
                 if (iSelection == 1 && iRandom == 1) 
                 {
                         printf("\nYou selected Rock!\n");
                         printf("\nYour computer selected Rock!\n");
                         printf("\nRock Ties Rock!\n");
                         flag = 'T';
                 }
       
                 else  if (iSelection == 1 && iRandom == 2) 
                 {
                        printf("\nYou selected Rock!\n");
                        printf("\nYour computer selected Paper!\n");
                        printf("\nPaper covers Rock!\n");
                        flag = 'L';
                 }
       
                 else  if (iSelection == 1 && iRandom == 3) 
                 {
                        printf("\nYou selected Rock!\n");
                        printf("\nYour computer selected Scissors!\n");
                        printf("\nRock crushes Scissors!\n");
                        flag = 'W';
                 }
       
                 else if (iSelection == 2 && iRandom == 1) 
                 {
                        printf("\nYou selected Paper!\n");
                        printf("\nYour computer selected Rock!\n");
                        printf("\nPaper covers Rock!\n");
                        flag = 'W';
                 }
       
                 else if (iSelection == 2 && iRandom == 2) 
                 {
                        printf("\nYou selected Paper!\n");
                        printf("\nYour computer selected Paper!\n");
                        printf("\nPaper ties Paper!\n");
                        flag = 'T';
                 }
       
                 else if (iSelection == 2 && iRandom == 3) 
                 {
                        printf("\nYou selected Paper!\n");
                        printf("\nYour computer selected Scissors!\n");
                        printf("\nScissors cuts Paper!\n");
                        flag = 'L';
                 }
       
                 else if (iSelection == 3 && iRandom == 1) 
                 {
                        printf("\nYou selected Scissors!\n");
                        printf("\nYour computer selected Rock!\n");
                        printf("\nRock crushes Scissors!\n");
                        flag = 'L';
                 }
       
                 else if (iSelection == 3 && iRandom == 2) 
                 {
                        printf("\nYou selected Scissors!\n");
                        printf("\nYour computer selected Paper!\n");    
                        printf("\nScissors cuts Paper!\n");
                        flag = 'W';
                 }
       
                 else if (iSelection == 3 && iRandom == 3) 
                 {
                        printf("\nYou selected Scissors!\n");
                        printf("\nYour computer selected Scissors!\n");
                        printf("\nScissors ties Scissors!\n");
                        flag  = 'T';
                 }
        
                validateFlag(flag, winCount,loseCount);
                printf("\n************************************");
                printf("\nDo you want to play Rock-Paper-Scissors? (y/n) ");
                scanf(" %c", &play);

		}while(play == 'y' || play == 'Y');

}