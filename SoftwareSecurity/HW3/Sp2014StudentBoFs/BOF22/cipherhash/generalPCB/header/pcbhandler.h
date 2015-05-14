/*
 * pcbhandler.h
 *
 *  Created on: Feb 15, 2015
 *      Author: hilberttaylor
 */


#ifndef PCBHANDLER_H
#define	PCBHANDLER_H

typedef enum {NEW, READY, WAITING, RUNNING,TERMINATED} state_t;


typedef enum {FCFS, SJF, RR} algoType_t;

struct PROGSTATUS
{
	char nameID[256];
	char PROC_NAME[256]       ;//Procedure name
	char PGM_STATUS[256]      ;//Status code
	char PRV_STATUS[256]       ;//Previous status
	char ROUTINE[256]         ;//Routine name
	int EXCP_TYPE         ;//Exception type
	int EXCP_NUM          ;//Exception number
	int EXCP_ID        ;//Exception Id
	char *DATE           ;//Date (DATE fmt)
	int YEAR              ;//Year (YEAR fmt)
	char LAST_FILE[256]       ;//Last file used
	char FILE_INFO[256]      ;//File error info
	char JOB_NAME[256]        ;//Job name
	char USER[256]            ;//User name
};
typedef struct PROGSTATUS progStatus_t ;

struct SCHEDULING
{
	char scheduler[5];
	int tQ;//time quantum
};
typedef struct SCHEDULING  scheduling_t;
struct processControlBlock
{
	int Registers;
	// List_t *prgCounter;//Program Counter
	progStatus_t *pgmStatus;//Program Status Word
	char stateDef[12] ;//Process State
	int proPriority;// Priority
	scheduling_t scheduling;//Scheduling Parameters
	int PID;//Process ID
	int timeStarted;//Time when process started
	int cpuTime;//CPU time used
	int burstTime;//Time to finish a process execution
};
typedef struct processControlBlock processControlBlock_t;

struct linkedprocess_t;

typedef struct linkedprocess_t
{
	int rootPID;
	processControlBlock_t *PCB;
	struct linkedprocess_t *next;
	struct linkedprocess_t *prev;
}linkedprocess_t;

typedef struct processlist_t
{
	int processCount;
	struct linkedprocess_t *first;
	struct linkedprocess_t *last;
}processlist_t ;

void readPcb(processControlBlock_t *PCB);// Read PCB
void processControlBlock_t_set(processControlBlock_t* PCB, int Registers,
		progStatus_t *pgmStatus,char stateDef[12],
		int proPriority,scheduling_t scheduling,int PID,
		int timeStarted, int cpuTime, int burstTime);//Set values to PCB


void processControlBlock_t_clear(processControlBlock_t *PCB);// clear all the value from a PCB

progStatus_t *progStatus_t_set(progStatus_t *pgmStatus,char nameID[256],char PROC_NAME[256],
		char PGM_STATUS[256],int  PRV_STATUS ,char ROUTINE[256] ,int EXCP_TYPE ,int EXCP_NUM ,
		int EXCP_ID , char DATE[256],int YEAR ,char LAST_FILE[256],char FILE_INFO[256],
		char JOB_NAME[256] ,char USER[256]);//Set values to Program status

void progStatus_t_View(progStatus_t *pgmStatus);// Display all the value of a Program status

void processlist_t_destroy(processlist_t *processlist); //Destroys a list of processes and any elements it might have.
void processlist_t_clear(processlist_t *processlist);// function for freeing the values in each node, not the nodes.
void processlist_t_clear_destroy(processlist_t *processlist);//Clears and destroys a list of processes

#define processlist_t_count(A) ((A)->processCount)
#define processlist_t_first(A) ((A)->first != NULL ? ((A)->first->rootPID, (A)->first->PCB): NULL)
#define processlist_t_last(A) ((A)->last != NULL ? ((A)->last->rootPID,(A)->first->PCB) : NULL)

void processlist_t_push(processlist_t *processlist, int rootPID,
		processControlBlock_t *PCB);//adds a new element to the end of the list

void processlist_t_insert_after(processlist_t *processlist, int rootPID, processControlBlock_t *PCB);
void processlist_t_insert_before(processlist_t *processlist, int rootPID, processControlBlock_t *PCB);

void *processlist_t_pop(processlist_t *processlist);// takes the last element off and returns it.

void processlist_t_unshift(processlist_t *processlist, int rootPID,
		processControlBlock_t *PCB);//add elements to the front of the list
void *processlist_t_shift(processlist_t *processlist);//removes the first element and returns it

linkedprocess_t *processlist_t_remove(processlist_t *processlist, linkedprocess_t* knot);//removes an knot from the front; the end; both front and end; or middle
linkedprocess_t *processlist_PCB_delete(processlist_t *processlist, int rootPID);

void processlist_t_display(processlist_t *processlist); //Displays a list of processes and any elements it might have.
void processlist_t_viewPCB(processControlBlock_t* knot);// function for Displaying the values in a given PCB.



//Iterates over the elements in the list.
#define PROCESSLIST_FOREACH(L, S, M, V) linkedprocess_t *_knot = NULL;\
		linkedprocess_t *V = NULL;\
		for(V = _knot = L->S; _knot != NULL; V = _knot = _knot->M)

#endif	/* PCBHANDLER_H */

