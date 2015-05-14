#include <stdio.h>

void main()
{
char q1[6];
char q2[5];
char q3[7];
char q1answer[7]="makkah";
char q2answer[6]="ameen";
char q3answer[8]="samsung";
int k=0;
int h=0;
int w=0;
printf("To reset your password answer the folloing questions\n");
while(k==0)
{
	printf("\nWhat city you born in?\n");
	scanf("%s",&q1);
	if(strcmp(q1,q1answer,6)==0){
	k++;}
	else{
	printf("\nPlease enter valid answer\n");
	}
}
while(h==0)
{
	printf("\nWhat is your father name?\n");
	scanf("%s",&q2);
	if(strcmp(q2,q2answer,5)==0){
	h++;}
	else
	{printf("\nplease enter valid answer\n");}
}
while(w==0)
{
	printf("\nWhat is your phone?\n");
	scanf("%s",&q3);
	if(strcmp(q3,q3answer,7)==0)
	{w=1;}
	else
	{printf("\nplease enter a valid answer\n");}
}
printf("\nNow you can reset your password");
}
