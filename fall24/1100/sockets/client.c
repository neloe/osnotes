#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int sock;

int main(int argc, char* argv[])
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		perror("Socket failed");
		exit(1);
	}
	struct sockaddr_in addr;
	struct hostent * host = gethostbyname("localhost");
	if(!host)
	{
		perror("Existential crisis");
		close(sock);
		exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	memcpy(&addr.sin_addr, host->h_addr, host->h_length);

	if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in))==-1)
	{
		perror("Connect failed");
		close(sock);
		exit(1);
	}

	char msg[] = "Never gonna give you up";
	write(sock, msg, strlen(msg)+1);
	int bytes_read = read(sock, msg, strlen(msg)+1);
	printf("bytes read: %d, message: %s\n", bytes_read, msg);
	close(sock);
	return 0;
}
