#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
int sockfd;

void cleanup(int sig);

int main(int argc, char* argv[])
{
  short port = 9999;
  signal(SIGINT, cleanup);
  printf("%d\n", port);
  printf("%d\n", htons(port));
  //printf("%ld\n", *((long *)&port));

  // 1. create the socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    perror(argv[0]);
    exit(1);
  }

  // 2. Bind to a port
  struct sockaddr_in sin;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) == -1)
  {
    close(sockfd);
    perror(argv[0]);
    exit(1);
  }

  // 3. Wait for incoming connections
  if (listen(sockfd, 10) == -1)
  {
    close(sockfd);
    perror(argv[0]);
    exit(1);
  }

  int client = accept(sockfd, NULL, NULL);
  if (client == -1)
  {
    perror(argv[0]);
    exit(1);
  }
  return 0;
}

void cleanup(int sig)
{
  close(sockfd);
  exit(0);
}
