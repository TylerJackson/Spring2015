#include < stdio.h > 
#include < stdlib.h > 
#include < string.h > 
int checkauth ( char *password) 
{ int aflag = 0; 
char pbuffer[ 16]; 
strcpy( pbuffer, password); 
if( strcmp( pbuffer, "P@ssword123") = = 0) aflag = 1; 
if( strcmp( pbuffer, "@m0niUmSulphat3") = = 0) aflag = 1;
return aflag; 
} 
int main( int argc, char *argv[]) 
{ 
if( argc < 2) 
{ 
printf(" Usage: %s < password >\ n", argv[ 0]); 
exit( 0); 
} 
if( checkauth( argv[ 1])) 
{ 
printf("\ n***************\ n"); 
printf(" Access Granted.\ n"); 
printf("*****************\ n"); 
} 
else 
{ printf("\ nAccess Denied.\ n");    
} 
}
