/*
 * pcbhandler.c
 *
 *  Created on: Feb 15, 2015
 *      Author: hilberttaylor
 */

#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <string.h>
#include "bughandler.h"
#include "datastructure.h"
#include "pcbhandler.h"
#include "utility.h"

void ReadPcb(processControlBlock_t *PCB)
{
	int Registers;
	//    List_t *prgCounter;//Program Counter
	progStatus_t *pgmStatus;//Program Status Word
	char stateDef[12] ;//Process State
	int proPriority;// Priority
	scheduling_t scheduling;//Scheduling Parameters
	int PID;//Process ID
	int timeStarted=0;//Time when process started
	int cpuTime=0;//CPU time used
	int burstTime;//Time to finish a process execution

	int enumPos;

	printf("\n The following Data Will be requested:");
	printf("\n          The Registers");
	printf("\n          The Program Status informations");
	printf("\n          The Process Priority");
	printf("\n          The Process Scheduling Parameters ");
	printf("\n          The Time to finish the process execution");
	printf("\n          The Process Identifier \n");

	printf("Enter the  Registers address : ");
	Registers = readInputInt();
	pgmStatus=(struct progStatus_t *)malloc(sizeof(progStatus_t));
	pgmStatus->DATE=curentSysTime();
	printf("\n Program status : \n");
	printf("         Enter the  Program status Identifier: ");
	stringCopy(readInputStr(),pgmStatus->nameID);
	printf("         Enter the  Program Name : ");
	stringCopy(readInputStr(),pgmStatus->PROC_NAME);
	printf("         Enter the  Program status code: ");
	stringCopy(readInputStr(),pgmStatus->PGM_STATUS);
	printf("         Enter the  Program Previous status: ");
	stringCopy(readInputStr(),pgmStatus->PRV_STATUS);
	printf("         Enter the  Routine name: ");
	stringCopy(readInputStr(),pgmStatus->ROUTINE);
	printf("         Enter the  Exception type : ");
	pgmStatus->EXCP_TYPE=readInputInt();
	printf("         Enter the  Program Exception number: ");
	pgmStatus->EXCP_NUM=readInputInt();
	printf("         Enter the  Program status Exception Id: ");
	pgmStatus->EXCP_ID=readInputInt();
	printf("         Enter the  Job name: ");
	stringCopy(readInputStr(),pgmStatus->JOB_NAME);
	printf("         Enter the  USER  ");
	stringCopy(readInputStr(),pgmStatus->USER);
	printf("        Program status Date : %s", pgmStatus->DATE);
	stringCopy("NEW", stateDef) ;
	printf("Enter the  Process priority : ");
	proPriority=readInputInt();
	printf("Select the scheduler type {1 for FCFS; 2 for  SJF ; 3 for RR} : ");

	do{
		scanf(" %d", &enumPos);
		(void) getchar(); //remove the '\n' from the keyboard stream
		switch(enumPos)
		{
		case 1 : stringCopy("FCFS",scheduling.scheduler);break;
		case 2 : stringCopy("SJF",scheduling.scheduler);break;
		case 3 : stringCopy("RR",scheduling.scheduler);break;
		default :
			printf("             Please select only from the above value   : " );
		}
	}while ((enumPos!=1) && (enumPos !=2) && (enumPos!=3) );
	printf("Enter the  Burst Time : ");
	burstTime=readInputInt();
	printf("Enter the  Process ID Number: ");
	PID=readInputInt();
	processControlBlock_t_set(PCB, Registers,pgmStatus,stateDef,proPriority,scheduling,PID,timeStarted,cpuTime,burstTime);
}

void processControlBlock_t_set(processControlBlock_t *PCB, int Registers,
		progStatus_t *pgmStatus,char stateDef[12],
		int proPriority,scheduling_t scheduling,int PID,
		int timeStarted, int cpuTime, int burstTime)//Set values to PCB
{

	PCB->Registers = Registers;
	//        PCB-> prgCounter=prgCounter;//Program Counter
	PCB-> pgmStatus=pgmStatus;//Program Status Word
	stringCopy(stateDef, PCB->stateDef);//Process State
	PCB-> proPriority= proPriority;// Priority
	PCB-> scheduling=scheduling;//Scheduling Parameters
	PCB-> PID=PID;//Process ID
	PCB-> timeStarted=timeStarted;//Time when process started
	PCB-> cpuTime=cpuTime;//CPU time used
	PCB-> burstTime=burstTime;//Time to finish a process execution
}

void processControlBlock_t_clear(processControlBlock_t *PCB)
{
	if (PCB) {
		if(PCB-> pgmStatus) {
			free(PCB->pgmStatus);
		}
	}
}

//progStatus_t *progStatus_t_set(progStatus_t *pgmStatus,char nameID[256],char PROC_NAME[256],
//		char PGM_STATUS[256],int  PRV_STATUS ,char ROUTINEs[256] ,int EXCP_TYPE ,int EXCP_NUM ,
//		int EXCP_ID , char DATE[256],int YEAR ,char LAST_FILE[256],char FILE_INFO[256],
//		char JOB_NAME[256] ,char USER[256])//Set values to Program status
//{
//	pgmStatus->nameID = nameID;
//	pgmStatus->PROC_NAME = PROC_NAME;
//	pgmStatus->PGM_STATUS = PGM_STATUS;
//	pgmStatus->PRV_STATUS = &PRV_STATUS;
//	pgmStatus->ROUTINE = ROUTINEs;
//	pgmStatus->EXCP_TYPE = EXCP_TYPE ;
//	pgmStatus->EXCP_NUM = EXCP_NUM;
//	pgmStatus->EXCP_ID = EXCP_ID;
//	pgmStatus->DATE = DATE;
//	pgmStatus->YEAR = YEAR;
//	pgmStatus->LAST_FILE = LAST_FILE;
//	pgmStatus->FILE_INFO = FILE_INFO;
//	pgmStatus->JOB_NAME = JOB_NAME;
//	pgmStatus->USER =USER;
//
//}


void processlist_t_destroy(processlist_t *processlist)
{
	PROCESSLIST_FOREACH(processlist, first, next, cur)
                    																				{
		if(cur->prev) {
			free(cur->prev);
		}
                    																				}
	free(processlist->last);
	free(processlist);
}

void processlist_t_clear(processlist_t *processlist)
{
	PROCESSLIST_FOREACH(processlist, first, next, cur) {
//		free(cur->rootPID);
		processControlBlock_t_clear(cur->PCB);
	}
}

void processlist_t_clear_destroy(processlist_t *processlist)
{
	processlist_t_clear(processlist);
	processlist_t_destroy(processlist);
}

void processlist_t_push(processlist_t *processlist, int rootPID,processControlBlock_t *PCB)
{
	linkedprocess_t *knot = malloc(sizeof(linkedprocess_t));
	check_mem(knot);
	knot->rootPID = rootPID;
	knot->PCB=PCB;
	if(processlist->last==NULL) {
		processlist->first = knot;
		processlist->last = knot;
	} else {
		processlist->last->next = knot;
		knot->prev = processlist->last;
		processlist->last = knot;
	}
	processlist->processCount ++;
	error:
	return;
}

void *processlist_t_pop(processlist_t *processlist)
{
	linkedprocess_t* knot = processlist->last;
	return knot != NULL ? processlist_t_remove(processlist, knot) : NULL;
}

void processlist_t_unshift(processlist_t *processlist, int rootPID, processControlBlock_t *PCB)
{
	linkedprocess_t *knot = malloc(sizeof(linkedprocess_t));
	check_mem(knot);
	knot->rootPID = rootPID;
	knot->PCB = PCB;
	if(processlist->first == NULL) {
		processlist->first = knot;
		processlist->last = knot;
	} else {
		knot->next = processlist->first;
		processlist->first->prev = knot;
		processlist->first = knot;
	}

	processlist->processCount++;

	error:
	return;
}

void *processlist_t_shift(processlist_t *processlist)
{
	linkedprocess_t *knot = processlist->first;
	return knot != NULL ? processlist_t_remove(processlist, knot) : NULL;
}

linkedprocess_t *processlist_t_remove(processlist_t *processlist, linkedprocess_t* knot)
{
	linkedprocess_t *result = NULL;

	check(processlist->first && processlist->last, "process list_t is empty.");
	check(knot, "knot can't be NULL");

	if(knot == processlist->first && knot == processlist->last) {
		processlist->first = NULL;
		processlist->last = NULL;
	} else if(knot == processlist->first) {
		processlist->first = knot->next;
		check(processlist->first != NULL, "Invalid process list, somehow got a first that is NULL.");
		processlist->first->prev = NULL;
	} else if (knot == processlist->last) {
		processlist->last = knot->prev;
		check(processlist->last != NULL, "Invalid process list, somehow got a next that is NULL.");
		processlist->last->next = NULL;
	} else {
		linkedprocess_t *after = knot->next;
		linkedprocess_t *before = knot->prev;
		after->prev = before;
		before->next = after;
	}

	processlist->processCount--;

	result = knot;
	free(knot);
	error:
	return result;
}

linkedprocess_t *processlist_PCB_delete(processlist_t *processlist, int rootPID)
{
	linkedprocess_t* knot;
	PROCESSLIST_FOREACH(processlist, first, next, cur) {
		if (cur->rootPID==rootPID) {
			knot=cur;
			break;
		}
	}
	knot=processlist_t_remove(processlist,knot);
	return knot;
}
void processlist_t_insert_after(processlist_t *processlist, int rootPID, processControlBlock_t *PCB)
{
	PROCESSLIST_FOREACH(processlist, first, next, cur) {
		if (cur->rootPID==rootPID) {
			linkedprocess_t *knot = malloc(sizeof(linkedprocess_t));
			check_mem(knot);
			knot->rootPID = PCB->PID;
			knot->PCB=PCB;
			if(processlist->last==cur) {
				processlist->last->next = knot;
				knot->prev = processlist->last;
				processlist->last = knot;
			} else {
				knot->next=cur->next;
				cur->next=knot;
				cur->next->prev=knot;
				knot->prev=cur;
			}
			break;
		}
	}
	processlist->processCount ++;
	error:
	return;
}
void processlist_t_insert_before(processlist_t *processlist, int rootPID, processControlBlock_t *PCB)
{
	PROCESSLIST_FOREACH(processlist, first, next, cur) {
		if (cur->rootPID==rootPID) {
			linkedprocess_t *knot = malloc(sizeof(linkedprocess_t));
			check_mem(knot);
			knot->rootPID = PCB->PID;
			knot->PCB=PCB;
			if(processlist->last==cur) {
				knot->next = processlist->first;
				processlist->first->prev = knot;
				processlist->first = knot;
			} else {
				knot->next=cur;
				cur->prev->next=knot;
				knot->prev=cur->prev;
				cur->prev=knot;
			}
			break;
		}
	}
	processlist->processCount ++;
	error:
	return;
}

void progStatus_t_View(progStatus_t *pgmStatus)
{
	if (pgmStatus) {
		if (pgmStatus->nameID) printf("--=>>Name             : %s\n",pgmStatus->nameID);
		if (pgmStatus->PROC_NAME) printf("--=>>Procedure NAME   : %s\n",pgmStatus->PROC_NAME);
		if (pgmStatus->PGM_STATUS) printf("--=>>Status           : %s\n",pgmStatus->PGM_STATUS);
		if (pgmStatus->PRV_STATUS) printf("--=>>Previous status  : %s\n",pgmStatus->PRV_STATUS);
		if (pgmStatus->ROUTINE) printf("--=>>Routine          : %s\n",pgmStatus->ROUTINE);
		if (pgmStatus->EXCP_TYPE) printf("--=>>Exception Type   : %d\n",pgmStatus->EXCP_TYPE);
		if (pgmStatus->EXCP_NUM) printf("--=>>Exception Number : %d\n",pgmStatus->EXCP_NUM);
		if (pgmStatus->EXCP_ID) printf("--=>>Exception ID     : %d\n",pgmStatus->EXCP_ID);
		if (pgmStatus->JOB_NAME) printf("--=>>Job Name         : %s\n",pgmStatus->JOB_NAME);
		if (pgmStatus->USER) printf("--=>>User             : %s\n",pgmStatus->USER);
		if (pgmStatus->DATE) printf("--=>>Date             : %s\n",pgmStatus->DATE);
	}
}

void processlist_t_viewPCB(processControlBlock_t* knot)
{
	printf("===>The  Process ID Number  : %d\n",knot->PID);
	printf("--Registers address          : %d\n",knot->Registers);
	printf("--Process State              : %s\n",knot->stateDef);
	printf("--Process priority           : %d\n",knot->proPriority);
	printf("--Process the scheduler type : %s\n",knot->scheduling.scheduler);
	printf("--Process burstTime          : %d\n",knot->burstTime);
	printf("--Program status             : \n");
	progStatus_t_View(knot->pgmStatus);
}

void processlist_t_display(processlist_t *processlist)
{
	int i=0;
	PROCESSLIST_FOREACH(processlist, first, next, cur) {
		printf(" PCB Number:  \%d\n",++i);
		processlist_t_viewPCB(cur->PCB);
		printf("\n<=+=+=+=+=+=+=+=<<<<<<+>>>>>>=+=+=+=+=+=+=+=+=>\n");
		myflush ( stdin );
	}
}
