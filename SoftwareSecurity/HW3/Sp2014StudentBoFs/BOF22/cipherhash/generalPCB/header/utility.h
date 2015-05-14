/*
 * utility.h
 *
 *  Created on: Feb 15, 2015
 *      Author: hilberttaylor
 */


#ifndef UTILITY_H
#define	UTILITY_H


void PressEnterToContinue(void);
void myflush ( FILE *in );
int clean_stdin();
char* readInputStr();
int readInputInt ();
int clean_stdin(void);
char * curentSysTime(void);
void stringCopy(char str1[],char str2[]);


#endif	/* UTILITY_H */

