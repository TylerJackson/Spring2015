/*
 ============================================================================
 Name        : generalPCB.c
 Author      : Hilbert Taylor Nzia
 Version     :
 Copyright   : Created on: Feb 15, 2015
 Description : General Process Management
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include <time.h>
#include "datastructure.h"
/*
 *
 */


  /**/
// public:
//    ProccessBlockList()//Constructor to initialize PCB contents
//    {
//     state=READY;
//      burstTime=5;
//    }
//    void addProcess(int PID)
//    {
//        printf("%d", "Enter Burst Time ");
//        scanf("%d", &burstTime);
//        in>>burstTime;
//        ProcessID=PID;
//    }
//    void updateProcessBlock(state_t S)
//    {
//     state=S;
//    }
//
//void executeProcess(int timeSlot)
//{
//    printf("%s\n","*******Load the PCB of Process " + ProcessID + "*********");
//    state="Running";
//    printf("%s\n","Process ID= " + ProcessID);
//    printf("%s\n","State= " + state);
//    printf("%s\n","Burst time= " + burstTime);
//    if((burstTime-timeSlot)>0)
//    {
//        printf("%s\n","Remaining Time to finish "  + (burstTime-timeSlot));
//        printf("%s\n","***Save the PCB of Process " + ProcessID);
//    }else
//    {
//        state="Dead";
//        printf("%s\n","****Process " + ProcessID + " Has finished and exited***");
//    }
//}
//

//
//int main(int argc, char** argv) {
//{
//  int hover=0;
//  int timeSlot=1; //Set processor time slice
//  ProccessBlockList plist[10];//Declare PCB for  processes
//for(int k=0;k<5;k++)
//{
//plist[k].addProcess((k+1)); //Create a new processes
//hover +=plist[k].burstTime;//Calculate the total time required to finish all processes
//}
// //start process execution
//while(hover != 0)
//{
//for(int i=0; i<5; i++)
//{
//if(plist[i].burstTime > 0)
//{
//if(plist[i].burstTime > timeSlot)
//{
//plist[i].updateProcessBlock("Ready");//Load the PCB ofprocess number i
//plist[i].executeProcess(timeSlot); //Run the Process number i
//plist[i].burstTime -= timeSlot; //Reduce the burst time by time slot
//hover -= timeSlot; //Reduce the total time required to finish all processes
//}
//else
//{
//plist[i].updateProcessBlock("Ready"); //Load and update the PCB of process number i
//plist[i].executeProcess(plist[i].burstTime);//Run the Process number i
//hover -= plist[i].burstTime; //Reduce the total time required to finish all processes
//plist[i].burstTime = 0; //Set Burst Time to zero if finished
//}
//}
//}
//}
int main(){
    menu();
    PressEnterToContinue();
    system("clear");
return (EXIT_SUCCESS);
}
