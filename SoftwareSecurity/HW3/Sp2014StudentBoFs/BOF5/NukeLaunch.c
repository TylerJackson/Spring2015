//
//  NukeLaunch.c
//  
//
//  Created by Chandra, Aayush on 3/11/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readyToLaunch() {

    printf("\nCombination Accepted. Nukes all set to launch.\n");
    
    //More funtionality will go here...
}

int main()
{
    int count = 1, len, validUser = 0;
    
    char buff[9], combo[9];
    
    printf("Be Cautious: You are entering Nuke Control Center.\nEnter Combination: ");
    
    scanf("%s", combo);
    
    len = strlen(combo);
    
    while(len >= 9) //length check to avoid buffer-overflow
    {
        printf("Combination too big. STOP messing with the code. Only %d Chance(s) left. Try again: ", 3 - count);
        
        scanf("%s", combo);
        
        count++;
        
        len = strlen(combo);
        
        if(count == 3) //no. of attempts for password
        {
            break;
        }
    }
    
    strcpy(buff, combo);
    
    if(strcmp(buff, "NukeDPRK"))
    {
        printf("\nWrong Combination.\n");
    }
    
    else
    {
        printf("\nAuthenticating...\n");
        
        sleep(1);
        
        validUser = 1;
    }
    
    if(validUser)
    {
        readyToLaunch();
    }
    
    
    exit(0);
}
