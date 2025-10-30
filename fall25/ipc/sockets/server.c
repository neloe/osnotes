#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
int sockfd;
int client;
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

  // 4. Accept connection from client
  client = accept(sockfd, NULL, NULL);
  if (client == -1)
  {
    perror(argv[0]);
    exit(1);
  }
  printf("Client connected. yay\n");

  char message[256];
  int read_bytes = recv(client, message, 256, 0);
  if (read_bytes == 256)
    message[255]=0;
  else
    message[read_bytes]=0;
  printf("%d bytes read; %s\n", read_bytes, message);
  read_bytes = recv(client, message, 256, 0);
  printf("%d bytes read; %s\n", read_bytes, message);
  close(client);
  close(sockfd);
  return 0;
}

void cleanup(int sig)
{
  close(sockfd);
  close(client);
  exit(0);
}
