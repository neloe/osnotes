#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>

int sock;
int client;

void * readthr(void * args)
{
	char buffer[256];
	while(1)
	{
		read(client, buffer, 256);
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
		write(client, (void*)buffer, readin+1);
	}
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(9999);
	my_addr.sin_addr.s_addr = INADDR_ANY;

	if (sock == -1)
	{
		printf("Error creating socket\n");
		exit(1);
	}

	int success = bind(sock, (struct sockaddr*)&my_addr, sizeof(struct sockaddr_in));
	if (success == -1)
	{
		printf("error binding socket\n");
		close(sock);
		exit(1);
	}
	success = listen(sock, 10);
	if (success == -1)
	{
		printf("I am deaf, cannot listen\n");
		close(sock);
		exit(1);
	}

	client = accept(sock, NULL, NULL);
	pthread_t r, w;
	void * result;
	pthread_create(&r, NULL, readthr, NULL);
	pthread_create(&w, NULL, writethr, NULL);
	pthread_join(r, &result);
	pthread_join(w, &result);
	/*char data[256];
	read(client, data, 256);
	printf("Server got: %s", data);
	close(client);*/
	close(sock);
	return 0;
}
