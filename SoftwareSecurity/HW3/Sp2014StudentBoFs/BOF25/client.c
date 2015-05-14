// Framework code from J. Ryan posting
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>

#define PORTNUM 8001            // Port server is listening on

char buffer[512];
/* Connect and talk to the server */
int
main()
{
  struct sockaddr_in server;
  struct hostent *host;
  int s;

  /* Create an Internet family, stream socket */
  s = socket(AF_INET, SOCK_STREAM, 0);

  /* Did that work? */
  if (s < 0) {
    perror("socket()");
    exit(EXIT_FAILURE);
  }

  /* We are running the server on localhost for the minute */
  if ((host = gethostbyname("localhost")) == NULL) {
    perror("gethostbyname()");
    exit(EXIT_FAILURE);
  }

  /* Fill in the socket address structure */
  memset((char *)&server, '\0', sizeof (server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORTNUM);
  memcpy((char *)&server.sin_addr, host->h_addr_list[0], host->h_length);

  /* Connect to the server */
  if (connect(s, (struct sockaddr *)&server, sizeof (server)) < 0) {
    perror("connect()");
    exit(EXIT_FAILURE);
  }
  // Get the name request from the server
  recv(s, (void *) buffer, sizeof(buffer), 0);
  printf("%s", buffer);
  // Tell the server our name from console input
  fgets(buffer, sizeof(buffer), stdin);
  send(s, (void *) buffer, strlen(buffer)+1, 0);
  // Get the password request from the server
  recv(s, (void *) buffer, sizeof(buffer), 0);
  // Display to console
  printf("%s", buffer);
  // Tell the server the password from console input
  fgets(buffer, sizeof(buffer), stdin);
  send(s, (void *) buffer, strlen(buffer)-1, 0);
  // Get the result from the server
  recv(s, (void *) buffer, sizeof(buffer), 0);
  printf("%s", buffer);
  //
  // Framework code follows
  /* Close the socket */
  close(s);

  return (0);
}
