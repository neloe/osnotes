#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int sock;

int main(int argc, char* argv[])
{
  int port = 9999;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1)
  {
    perror(argv[0]);
    exit(1);
  }

  struct sockaddr_in server;
  struct hostent * host;
  host = gethostbyname("localhost");
  if (!host)
  {
    perror(argv[0]);
    exit(1);
  }
  server.sin_family=AF_INET;
  server.sin_port=htons(port);
  memcpy(&server.sin_addr, host->h_addr, host->h_length);
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
  {
    perror(argv[0]);
    exit(1);
  }
  write(sock, "Hello World", strlen("Hello World"));
  sleep(1);
  write(sock, "BOO", strlen("BOO")+1);
  close(sock);
  return 0;
}
