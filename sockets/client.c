#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

int sock;

void * readthr(void * args)
{
	char buffer[256];
	while(1)
	{
		read(sock, buffer, 256);
		printf("-- %s\n",  buffer);
	}
	pthread_exit(NULL);
}

void * writethr(void * args)
{
	char * buffer = calloc(256, sizeof(char));
	size_t buflen = 256;
	while(1)
	{
		int readin = getline (&buffer, &buflen, stdin);
		write(sock, (void*)buffer, readin+1);
	}
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	struct hostent * host;
	host = gethostbyname(argv[1]);
	if(host == NULL)
	{
		printf("404\n");
		exit(1);
	}

	if (sock == -1)
	{
		printf("Error creating socket\n");
		exit(1);
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9999);
	memcpy(&server.sin_addr, host->h_addr, host->h_length);

	int success = connect(sock, (struct sockaddr*)&server, sizeof(struct sockaddr_in));
	if (success == -1)
	{
		printf("Cannot connect\n");
		close(sock);
		exit(1);
	}
	
	//write(sock, (void*)mesg, strlen(mesg)+1);
	//printf("message sent\n");
	pthread_t r, w;
	void * result;
	pthread_create(&r, NULL, readthr, NULL);
	pthread_create(&w, NULL, writethr, NULL);
	pthread_join(r, &result);
	pthread_join(w, &result);
	close(sock);
	return 0;
}
