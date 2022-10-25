#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // 1 create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
	printf("Roh roh raggy, bad socket\n"); // TODO log error less bad
	exit(1);
    }
    // 2 bind socket
    // 2.1: set up our address
    struct sockaddr_in saddrin;
    saddrin.sin_family = AF_INET;
    saddrin.sin_port = htons(9999);
    printf("%d %d\n", 9999, htons(9999));
    saddrin.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd, (struct sockaddr *)&saddrin, sizeof(saddrin)) == -1)
    {
	printf("error on bind; boom\n");
	close(sockfd);
	exit(1);
    }
    // listen for connections
    if(listen(sockfd, 1) == -1)
    {
	printf("See no evil, hear no evil; I hear nothing\n");
	close(sockfd);
	exit(1);
    }
    // accept connections
    int client = accept(sockfd, NULL, NULL);
    if (client == -1)
    {
	printf("I don't know how this happened\n");
	close(sockfd);
	exit(1);
    }
    // data-y stuff
    
    close(sockfd);
}
