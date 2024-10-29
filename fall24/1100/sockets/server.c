#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int sock, client;

int main(int argc, char* argv[])
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		perror("Failed to create socket");
		exit(1);
	}

	printf("%d, %d\n", 9999, htons(9999));
	struct sockaddr_in address;
	address.sin_port = htons(9999);
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_family = AF_INET;

	if (bind(sock, (struct sockaddr*)&address, sizeof(struct sockaddr_in)) == -1)
	{
		perror("Bind failed");
		close(sock);
		exit(1);
	}

	if (listen(sock, 10) == -1)
	{
		perror("Listen failed");
		close(sock);
		exit(1);
	}

	client = accept(sock, NULL, NULL);
	if (client == -1)
	{
		perror("accept failed");
		close(sock);
		exit(1);
	}

	char recvd [256];
	char msg[] = "go away";

	int bytes_read = read(client, recvd, 256);
	printf("bytes read: %d, msg: %s\n", bytes_read, recvd);

	write(client, msg, strlen(msg));

	close(client);
	close(sock);


	return 0;
}
