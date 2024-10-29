#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>

int sock;

int main(int argc, char* argv[])
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		printf("cannot create socket\n");
		exit(1);
	}
	struct sockaddr_in server;
	struct hostent * host;

	host = gethostbyname("127.0.0.1");
	if (!host)
	{
		printf("I am having an existential crisis\n");
		exit(1);
	}

	server.sin_family=AF_INET;
	server.sin_port=htons(9999);
	memcpy(&server.sin_addr, host->h_addr, host->h_length);
	if (connect(sock,(struct sockaddr*)&server, sizeof(struct sockaddr_in))==-1)
	{
		printf("Connection failed\n");
		close(sock);
		exit(1);
	}

	char msg[] = "I'm a lumberjack and I'm ok";

	write(sock, msg, strlen(msg)+1);
	int bytes_read = read(sock, msg, strlen(msg)+1);
	printf("bytes read: %d, message: %s\n", bytes_read, msg);
	close(sock);
	return(0);
}
