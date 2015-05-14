#include<stdio.h>
#include<string.h>

int main(void)
{
char buff[15];
int pass = 0;
unsigned long amount= 1000, deposit, withdraw;
int choice,k;
int attemp = 1;
int s = 4;

printf("\n ENTER YOUR SECRET PIN NUMBER\n");
scanf("%s",&buff);
s = strcmp(buff,"1250");


while(s != 0 && attemp < 3)
{
		printf("\nWrong password\n");
                 printf("PLEASE ENTER VALID PASSWORD\n");
		scanf("%s",&buff);
		s = strcmp(buff,"1250");
                 attemp = attemp +1; 
}


if(attemp == 3 && s != 0)
{
return;
}
pass =1;


if(pass)
{
printf("**************** welcome to ATM service*************\n");
printf("1. Check Balance\n");
printf("2. Withdraw Cash\n");
printf("3. Deposit Cash\n");
printf("4. Quit\n");
printf("*******************************************************\n");
printf("Enter your choice: ");
scanf("%d", &choice);


switch(choice)
{
case 1:
printf("\n YOUR BALANCE IN $ : %lu ", amount);
break;

case 2:
printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
scanf("%lu", &withdraw);
if( withdraw % 100 != 0)
{
printf("\n PLEASE ENTERT THE AMOUNT IN MULTIPLES OF 100\n");
}
else if( withdraw > (amount - 500))
{
printf("\n INSUFFICENT BALANCE");
}
else
{
amount = amount - withdraw;
printf("\n\n PLEASE COLLECT CASH\n");
printf("\n YOUR CURRENT BALANCE IS%lu", amount);
}
break;

case 3:
printf("\n ENTER THE AMOUNT TO DEPOSIT\n");
scanf("%lu", &deposit);
amount = amount + deposit;
printf("YOUR BALANCE IS %lu", amount);
break;

case 4:
printf("\n THANK U USING ATM\n");
break;

default:
printf("\n INVALID CHOICE\n");
}

}
return 0;
}
