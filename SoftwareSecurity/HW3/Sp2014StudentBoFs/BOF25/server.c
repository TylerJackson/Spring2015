//
// Server framework courtesy of a posting by J. N. Ryan
/*
 * Our vulnerable server.  It asks the user for his name and password.  If the
 * password hashes correctly it takes action.
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>
#include <openssl/sha.h>
#include <fcntl.h>

#define PORTNUM 8001

// Non-framework by Andrea Roth
#define BLEN 512
char canary[9];
char hello[]="Hello ";
char whatis[]=" what is your password?\n";
char badPass[]="Password incorrect\n";
char launch[]="Password correct, thermonuclear missile launched\n";

SHA_CTX shactx;
unsigned char digest[SHA_DIGEST_LENGTH];
unsigned char correctDigest[SHA_DIGEST_LENGTH]={0xbf, 0xc5, 0xa1, 0x3b, 0x59, 0x24, 0xf2, 0xb2, 0xc4, 0x59, 0x68, 0xb9, 0x76,
                                                0xd0, 0x97, 0x3a, 0x67, 0xb9, 0x01, 0x66};

// Andrea Roth code, conforming to fremework conventions

/* Get the password and calculate the digest  */
void
getpassdigest(int s, char * buffer_p, char * nameBuffer_p)
{
  char passBuffer[12+9]; // 10 character password, \n, null terminator
  // Protect the password buffer by putting a canary at the end
  strcpy(&passBuffer[12],canary);

  /* Ask for the user's name */
  snprintf(buffer_p, BLEN,"What is your user name?\n");
  send(s, (void *)buffer_p, strlen(buffer_p)+1, 0);
  /* Receive the answer */
  recv(s, (void *)nameBuffer_p, BLEN, 0);
  nameBuffer_p[strlen(nameBuffer_p)-1] = 0; // Eliminate \n
  /* Construct request for the password */
  snprintf(buffer_p, BLEN, hello);
  snprintf(&buffer_p[sizeof(hello)-1], BLEN, nameBuffer_p);
  snprintf(&buffer_p[strlen(buffer_p)], BLEN, whatis);
  /* Send question to client */
  send(s, (void *)buffer_p, strlen(buffer_p)+1, 0);
  /* Get the password's hash  */
  recv(s, (void *)passBuffer, BLEN, 0);
  passBuffer[11] = 0; // Change \n to 0
  if (memcmp(&passBuffer[12],canary, 8))
  {
      //printf("%s\n", &passBuffer[12]); //// debug only
      printf("Buffer overflow detected\n");
      exit(EXIT_FAILURE);
  }
  SHA1_Init(&shactx);
  SHA1_Update(&shactx, passBuffer, 10);
  SHA1_Final(digest, &shactx);
}

/* One thread per connection */
void *
handler(void *n)
{
  int   s;
  char *nameBuffer_p;
  char * buffer_p;
  char * finalMsg;
  
  // Get some memory buffers
  nameBuffer_p = malloc(BLEN);
  buffer_p     = malloc(BLEN);

  /* Detach */
  pthread_detach(pthread_self());

  /* Cast parameter */
  s = *((int *)n);

  // Prompt the user and get his password's digest
  getpassdigest(s, buffer_p, nameBuffer_p);
  if (memcmp(digest, correctDigest, SHA_DIGEST_LENGTH))
      finalMsg = badPass;
  else
      finalMsg = launch;
  printf(finalMsg);

  // Send result to client

  send(s, (void *)finalMsg, strlen(finalMsg)+1, 0);

  //Back to framework code
  
  /* Close the socket */
  close(s);

  /* Free memory */
  free(n);
  free(nameBuffer_p);
  free(buffer_p);
  return ((void *)NULL);
}

/* Connect and talk to a client */
int
main()
{
  struct sockaddr_in socketname, client;
  struct hostent *host;
  socklen_t clientlen = sizeof (client);
  pthread_t tid;
  int s, n, *c, optval = 1;

    // non-framework code by Andrea Roth

    int i;
    size_t result;
    unsigned char myRandomData;
    int fdRandom;
    // Get a random canary
    fdRandom = open("/dev/random", O_RDONLY);
    for (i = 0; i < 8; i++)
    {
        result = read(fdRandom, &myRandomData, 1);
        canary[i] = (myRandomData % 10) + '0'; 
    }
    canary[8] = 0;
    // printf("canary %s\n",canary); //// Debug only !!!!!!
    // Framework code starts again

  /* We will always be localhost */
  if ((host = gethostbyname("localhost")) == NULL) {
    perror("gethostbyname()");
    exit(EXIT_FAILURE);
  }

  /* Fill in the socket address structure */
  memset((char *)&socketname, '\0', sizeof (socketname));
  socketname.sin_family = AF_INET;
  socketname.sin_port = htons(PORTNUM);
  memcpy((char *)&socketname.sin_addr, host->h_addr_list[0], host->h_length);

  /* Create an Internet family, stream socket */
  s = socket(AF_INET, SOCK_STREAM, 0);

  /* Did that work? */
  if (s < 0) {
    perror("socket()");
    exit(EXIT_FAILURE);
  }

  /* Allow binding if waiting on kernel to clean up */
  if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof (optval)) < 0) {
    perror("setsockopt()");
    exit(EXIT_FAILURE);
  }

  /* Now bind the address to our socket so it becomes visible */
  if (bind(s, (struct sockaddr *)&socketname, sizeof (socketname)) < 0) {
    perror("bind()");
    exit(EXIT_FAILURE);
  }

  /* Make our now visible socket available for connections */
  if (listen(s, 5)) {
    perror("listen()");
    exit(EXIT_FAILURE);
  }

  /* Loop forever */
  while (1) {

    /* Accept a connection */
    n = accept(s, (struct sockaddr *)&client, &clientlen);

    /* Did that work? */
    if (n < 0) {
      perror("accept()");
      exit(EXIT_FAILURE);
    }

    /* Allocate room for socket for this thread */
    c = malloc(sizeof (*c));

    /* Check we got some memory */
    if (!c) {
      perror("malloc()");
      exit(EXIT_FAILURE);
    }

    /* Initialise */
    *c = n;

    /* Have a conversation */
    pthread_create(&tid, NULL, handler, (void *)c);
  }

  /* Close socket */
  close(s);

  return (0);
}
