#include <stdio.h>

void validate();
void getName();
void getExpirationDate();

int main(){
printf("Hello!! Welcome to SMU Online Students Video Downloads\n");
printf("In order to download th video's, you will have to enter the information and credit card details\n");
printf("Please provide the following information to get the access to the downloads\n");
getName();
getExpirationDate();
validate();
}

void getName(){
printf("Please enter the name on the card: ");
char userName[15];
scanf("%s", userName);
}


void getExpirationDate(){
printf("\nPlease enter the expiration date of the card in the same format: ");
char date[8];
scanf("%s", date);
}


void validate(){
char cc[16];
int m[] = {0,2,4,6,8,1,3,5,7,9};
char cvc[3];
char isCorrect='0';
int mod=1;
int i,odd = 1, sum = 0;
printf("\nEnter the 16 digit card number");
scanf("%s",cc);
printf("\nEnter the 3 digit cvc number");
scanf("%s",cvc);
   for (i = strlen(cc); i--; odd = !odd) {
                int digit = cc[i] - '0';
                sum += odd ? digit : m[digit];
        }
mod=sum%10;
if(mod==0)
isCorrect='1';
if(isCorrect=='1'){
printf("Thank you!!\n" );
printf("The video's will be downloded in a moment!");}
else
printf("Sorry please check your card details and try again!\n");
}

