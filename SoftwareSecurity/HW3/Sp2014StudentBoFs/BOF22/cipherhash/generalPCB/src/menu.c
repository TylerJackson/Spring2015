/*
 * menu.c
 *
 *  Created on: Feb 15, 2015
 *      Author: hilberttaylor
 */



#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "bughandler.h"
#include "utility.h"
#include "pcbhandler.h"

processControlBlock_t* PCB;
linkedprocess_t* knot;
processlist_t *PCBlist;
int PCB_PID=0;
int subMenu;

void addPCB(){
	system("clear");
	printf("              Add a new PCB\n");
	printf("Select where to add:... \n");
	printf("1 =>for the front             2 =>after a specific PCB  \n");
	printf("3 =>before a specific PCB     4 =>for the tail \n\n");
	printf("                  5 =>to stop adding  \n");
	PCB=(struct processControlBlock_t *)malloc(sizeof(processControlBlock_t));
	do{
		scanf(" %d", &subMenu);
		(void) getchar(); //remove the '\n' from the keyboard stream
		switch(subMenu)
		{
		case 1 : {
			ReadPcb(PCB);
			processlist_t_unshift(PCBlist, PCB->PID,PCB);
			printf("\nPCB added successfully\n");
		}
		;break;
		case 2 :
		case 3 :{
			printf("\n          Enter The Specific Process Identifier :");
			PCB_PID = readInputInt();
			ReadPcb(PCB);
			if (PCBlist->processCount==0){
				processlist_t_push(PCBlist, PCB->PID,PCB);
			}else if (subMenu==2){
				processlist_t_insert_after(PCBlist, PCB_PID,PCB);
			} else if (subMenu==3){
				processlist_t_insert_before(PCBlist, PCB_PID,PCB);
			}
			printf("\nPCB added successfully\n");
			break;
		}
		case 4 : {
			ReadPcb(PCB);
			processlist_t_push(PCBlist, PCB->PID,PCB);
			printf("\nPCB added successfully\n");
			break;
		}
		case 5 : {
			printf("\nNo PCB added \n");
			break;
		}
		default :
			printf("             Please select only from the above value   : " );
		}
	}while ((subMenu!=1) && (subMenu !=2) && (subMenu!=3)  && (subMenu!=4) && (subMenu!=5));
	myflush ( stdin );
	PressEnterToContinue;
}

void deletePCB(){

	system("clear");
	printf("              [D/d]elete a PCB\n");
	printf("Select where to delete:... \n");
	printf("1 from the front =====  2 from a specific PCB \n");
	printf("3 from the tail  ====== 4 to stop deleting  \n");
	do{
		scanf(" %d", &subMenu);
		(void) getchar(); //remove the '\n' from the keyboard stream
		switch(subMenu)
		{
		case 1 : {
			knot=processlist_t_shift(PCBlist);
			break;
		}
		case 2 :{
			printf("\n          Enter The Specific Process Identifier :");
			PCB_PID = readInputInt();
			knot=processlist_PCB_delete(PCBlist, PCB_PID);
			break;
		}
		case 3 : {
			knot=processlist_t_pop(PCBlist);
			break;
		}
		case 4 :  {
			printf("\nNo PCB deleted \n");
			break;
		}
		default :
			printf("             Please select only from the above value   : " );
		}
	}while ((subMenu!=1) && (subMenu !=2) && (subMenu!=3)  && (subMenu!=4));

	if (knot) {
		processlist_t_viewPCB(knot->PCB);
		printf("\nPCB Removed successfully\n");
	}else{
		printf("\nUnable to Remove the PCB With PID : %d,\n",PCB_PID);
	}
	myflush ( stdin );
	PressEnterToContinue;
	free(knot);
}

void findPCB(){
	system("clear");
	printf("              [F/f]ind a PCB \n");
	printf("\n          Enter The Specific Process Identifier :");
	PCB_PID = readInputInt();
	PROCESSLIST_FOREACH(PCBlist, first, next, cur) {
		if (cur->rootPID==PCB_PID) {
			printf("\nPCB Found....\n");
			processlist_t_viewPCB(knot->PCB);
			printf("\nPCB Removed successfully\n");
			break;
		}
	}
	if (cur==NULL){
		printf("\nUnable to find the PCB With PID : %d,\n",PCB_PID);
	}
	myflush ( stdin );
	PressEnterToContinue;
}

int menu() {

	//	PCB=(struct processControlBlock_t *)malloc(sizeof(processControlBlock_t));
	PCBlist=(processlist_t*)malloc(sizeof(processlist_t));
	PCBlist->processCount=0;

	char choice;

	system("clear");
	//this is the start of the menu()'s "big loop"
	do   {
		choice='\0';
		printf("\n                      Menu\n");
		printf("\n              General Process Management\n");
		printf("        [A/a]dd a PCB           [D/d]elete a PCB\n\n");
		printf("        [F/f]ind a PCB          [V/v]iew all PCBs \n\n");
		printf("        Your choice [or Q/q to quit]:\n");
		printf("    Type the Return/Enter key validate your choice:\n\n");

		subMenu=0;
		scanf(" %c", &choice,"\n");
		(void) getchar(); //remove the '\n' from the keyboard stream
		switch(choice)
		{
		case 'a' :
		case 'A' :{
			addPCB();
			break;
		}
		case 'D' :
		case 'd' :{
			deletePCB();
			break;
		}
		case 'F' :
		case 'f' :{
			findPCB();
			break;
		}
		case 'V' :
		case 'v' :{
			system("clear");
			printf("              [V/v]iew all PCBs\n\n");
			processlist_t_display(PCBlist);
			printf("\n\n+++++++END OF THE LIST+++++++++");
			myflush ( stdin );
			PressEnterToContinue;
			break;
		}
		case 'Q' :
		case 'q' :
			printf("Q/q to quit]:\n\n\n");
			free(PCBlist);
			return 1;
		default :
			printf("Please select only from the above menu" );
		}

		PressEnterToContinue;

		system("clear");
	}while(choice!='q'||choice!='Q');  //end of "big loop"

}
