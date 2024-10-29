#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int sock, client;

int main(int argc, char* argv[])
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		printf("Somehow we've screwed up creating a socket\n");
		exit(1);
	}
	struct sockaddr_in my_address;
	printf("%d, %d\n", 9999, htons(9999));
	my_address.sin_port = htons(9999);
	my_address.sin_family = AF_INET;
	my_address.sin_addr.s_addr = INADDR_ANY;

	if (bind(sock, (struct sockaddr*)&my_address, sizeof(struct sockaddr_in)) == -1)
	{
		printf("Cannot bind socket\n");
		perror("server");
		exit(1);
	}

	if (listen(sock, 10) == -1)
	{
		printf("listen failed\n");
		close(sock);
		exit(1);
	}

	client = accept(sock, NULL, NULL);
	if (client == -1)
	{
		printf("Accept failed\n");
		close(sock);
		exit(1);
	}

	char msg[256];
	char reply[] = "go away";
	int bytes_read = read(client, msg, 256);
	printf("bytes_read: %d, message: %s\n", bytes_read, msg);
	write(client, reply, strlen(reply)+1);

	close(client);
	if(close(sock) == -1)
		perror("socket close");
	return 0;
}
