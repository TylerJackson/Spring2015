#include <stdio.h>
#include <string.h>

int main(void){
	
	printf("\n Welcome to Death Star Control Panel!\n");
	
	char names[50];
	int name = 0;
	char ranks[10];
	int rank = 0;
	char passwords[50];
	int password = 0;
	
	printf("\n System: Please Enter your name!\n");
	scanf("%s",names);
	if(strncmp(names, "Vader",50)){
		printf("\n System: no such person exists! initating self destruct! \n");
	}else{
		printf("\n System: WHO?!! HOW DARE YOU?!! \n");
		name = 1;
	}

		if(name){
			printf("\n System: Please Enter your rank!\n");
			scanf("%s",ranks);
			if(strncmp(ranks, "Darth",10)){
				printf("\n System: Wrong Rank..Republic Spy! initating self destruct in 10 sec! \n");
			}else{
				printf("\n System: ....Darth ....Vader?!!!  \n");
				rank = 1;
			}
	
			if(rank){
				printf("\n System: Please Enter your Access Code!\n");
				scanf("%s",passwords);
				if(strncmp(passwords, "Skywalker",50)){
				printf("\n System: Wrong password, initating self destruct! \n");
			}else{
				printf("\n System: Correct password! Welcome Darth Vader! \n");
				password = 1;
			}
	
			if(password){
				printf ("\n System: Root Access to the Death Star has been Unlocked ... \n");		
			}		
		
		}		
		
	}	
	
		return 0;
}
