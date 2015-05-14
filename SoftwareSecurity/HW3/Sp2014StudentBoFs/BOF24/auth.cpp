#include <stdio.h>
#include <string.h>

int main(int argc, char**argv){
  int MAX_SIZE = 10;
  int authentication(0);
  char cUsername[MAX_SIZE], cPassword[MAX_SIZE];

  strcpy(cUsername, argv[1]);
  strcpy(cPassword, argv[2]);

  if(strcmp(cUsername, "admin") == 0 && strcmp(cPassword, "password") == 0){
    	authentication = 1;
  }

  if(authentication == 1){
    printf("Access granted\n");
  } else {
    printf("Wrong username and password\n");
  }
  return 0;
}