/*
 ============================================================================
 Name        : lowercasefile.c
 Author      : Hilbert Taylor Nzia
 Version     :
 Copyright   : Created Mar 15, 2015
 Description : !!!Convert a file to lower case character!!!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Convert a file to lower case character!!!"); /* prints !!!Convert a file to lower case character!!! */
	return EXIT_SUCCESS;
}

int lower(int c)
   {
   if(c >= 'A' && c <= 'Z')
      {
      return c + 'a' - 'A';
      }
   else
      {
      return c;
      }
   }
