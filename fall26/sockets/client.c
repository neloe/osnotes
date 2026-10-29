#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>

int sock;
char* in_buffer;

void * read_thr(void * args);
void signal_handler(int signum);

int main(int argc, char* argv[])
{
  signal(SIGINT, signal_handler);
  sock = socket(AF_INET, SOCK_STREAM, 0);
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
  //write(sock, "Hello World!", strlen("Hello World!")+1);
  //close(sock);
  pthread_t r;
  void * result;
  pthread_create(&r, NULL, read_thr, NULL);

  in_buffer = calloc(256, sizeof(char));
  size_t buflen = 256;
  while(1)
  {
	int readin = getline(&in_buffer, &buflen, stdin);
	write(sock, in_buffer, readin);
  }
  pthread_join(r, &result);
  return 0;
}

void * read_thr(void * args)
{
  char buffer[256];
  while(1)
  {
	read(sock, buffer, 256);
	printf("-- %s\n", buffer);
  }
}

void signal_handler(int signum)
{
  close(sock);
  free(in_buffer);
  exit(1);
}
