/* Lab2:  A program for a user known to the system to get root_secet if the
 * correct passcode is entered.
 *
 * Compile:
 * $ gcc -fno-stack-protector -o tell_secret tell_secret.c
 *
 * Usage: 
 * $ ./tell_secret <username> <passcode>
 *
 * Note:  This is a simple program that intentionally leaves a buffer overflow
 * vulnerability for exploit.  (There may be other unintended vulns.)
 *
 * Author:  Yan Lin
 *
 */
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <fcntl.h>


const char FILE_KEY[] = "Dis-moi!";

int check_key();
void tell_secret();

int main(int argc, char *argv[])
{
  struct passwd pwd;
  struct passwd *result;
  char *buf;
  size_t bufsize;
  int s;

  int rc;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <username> <passcode>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
  if (bufsize == -1)          /* Value was indeterminate */
      bufsize = 16384;        /* Should be more than enough */

  buf = malloc(bufsize);
  if (buf == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  s = getpwnam_r(argv[1], &pwd, buf, bufsize, &result);
  if (result == NULL)
  {
    if (s == 0)
    {
      printf("Not found\n");
    }
    else
    {
      errno = s;
      perror("getpwnam_r");
    }

    exit(EXIT_FAILURE);
  }

  rc = check_key(argv[2]);
  if(rc == 0) // key matched.
  {
    printf("Transferring data to %s:\n", pwd.pw_name);
    tell_secret();
  }
  else
  {
    printf("Not authorized.\n", rc);
    exit(EXIT_FAILURE);
  }
}


/* check_key:  checking if the user input matches the required key.
 *
 * input - user input string for the required key.
 *
 * return 0 if pass, -1 if fail.
 *
 */
int check_key(char *str)
{
  char buffer[20];
  int pass = 0;

  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, str);
  if(strncmp(buffer, FILE_KEY, sizeof(FILE_KEY)) == 0)
  {
    printf("Correct code.\n");
    pass = 1;
  }
  else
  {
    printf("Wrong code.\n");
  }

  if(pass)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

void tell_secret()
{
  int fd;
  char c;
  int n;

  fd = open("/root/root_secret", O_RDONLY);
  if(fd == -1)
  {
    perror("read");
    exit(EXIT_FAILURE);
  }

  printf("Root secret disclosed to you:  ");
  n = read(fd, &c, 1);
  while(n > 0)
  {
    // do not print the last '\n'
    if(c != 0xa)
    {
      c -= 4;
      printf("%c", c);
    }

    n = read(fd, &c, 1);
  }

  printf("\n");
}
