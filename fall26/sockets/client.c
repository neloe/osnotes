#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>


int main(int argc, char* argv[])
{
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  struct hostent * host;
  host = gethostbyname(argv[1]);
  if (host == NULL)
  {
	perror("404:");
	exit(1);
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(9999);
  mempcpy(&server.sin_addr, host->h_addr, host->h_length);
  int success = connect(sock, (struct sockaddr*)&server,
	                    sizeof(struct sockaddr_in));
  if (success == -1)
  {
	perror("Connect:");
	close(sock);
	exit(1);
  }
  write(sock, "Hello World!", strlen("Hello World!")+1);
  close(sock);
  return 0;
}
