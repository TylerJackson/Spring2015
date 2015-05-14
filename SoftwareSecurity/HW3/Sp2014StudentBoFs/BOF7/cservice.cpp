#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

bool waitForTurn(int position){
    while(position!=0){
        printf("You are currently number %u in the queue.\n",position);
    position--;
    sleep(1);
    }
    if(position!=0){
        puts("What have you done?");
        return false;
    }
    return true;
}

int main(){
    char natureOfVisit[30];

    puts("Welcome to Terra Bell Software Customer Service!\n");
      
    puts("Please enter the nature of your visit.");
    fgets(natureOfVisit,30,stdin);
    
    puts("Loading most recent error log...");
    ifstream errorLog;
	errorLog.open("error.log", ifstream::in);
	char errorCode[24];
    int position = rand()%10+10;
    while(!errorLog.eof()){
	    errorLog>>errorCode;    
    }        
    puts("Please wait for a representative to become available");    
    
    
    bool myTurn=waitForTurn(position);

    if(!myTurn){
        puts("Didn't you learn not to cut lines in kindergarten?");
    }
    else{
        puts("\nThank you for waiting. Looking at the error log... Norefundssorrybye.");
    }


    


}
