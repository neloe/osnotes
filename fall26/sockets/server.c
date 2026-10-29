#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <signal.h>
#include <pthread.h>


int sock;
int client;
char * buffer = NULL;

void * read_thr(void * args);
void interrupt_handler(int signum);

int main(int argc, char* argv[])
{
  signal(SIGINT, interrupt_handler);
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1)
  {
	perror("Socket Create:");
	exit(1);
  }
  struct sockaddr_in my_addr;
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(9999);
  //printf("Host ordering: 0x%X, net ordering: 0x%X\n", 9999, htons(9999));
  my_addr.sin_addr.s_addr = INADDR_ANY;
  int success = bind(sock, (struct sockaddr *)&my_addr, sizeof(struct sockaddr_in));
  if (success == -1)
  {
	perror("Socket Bind:");
	close(sock);
	exit(1);
  }
  success = listen(sock, 10);
  if (success == -1)
  {
	perror("Socket Listen:");
	close(sock);
	exit(1);
  }
  client = accept(sock, NULL, NULL);
  /*char data[256];
	read(client, data, 256);
	printf("Server got: %s\n", data);
	close(client);
	close(sock);*/
  pthread_t r;
  void * result;
  pthread_create(&r, NULL, read_thr, NULL);

  // Write to client
  buffer = calloc(256, sizeof(char));
  size_t buflen = 256;
  while(1)
  {
	int readin = getline (&buffer,&buflen, stdin);
	write(client, buffer, readin+1);
  }
  pthread_join(r, &result);
  return 0;
}
void interrupt_handler(int signum)
{
  close(client);
  close(sock);
  free(buffer);
  exit(1);
}
void * read_thr(void * args)
{
  char data[256];
  while(1)
  {
	read(client, data, 256);
	printf("-- %s\n", data);
  }
}
