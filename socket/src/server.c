#include "server.h"


#define SERVER_PORT 8080
#define SERVER_IP_1 "127.0.0.1"

int sockfd; //服务器套接字


int server_init(void)
{
	unsigned short port = SERVER_PORT;
	char *server_ip = SERVER_IP_1;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);//创建服务器套接字
	if (sockfd < 0)
	{
		perror("server sockfd create failed\n");
		exit(-1);
	}

	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

	int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (0 != ret)
	{
		perror("server bind failed\n");
		close(sockfd);
		exit(-1);
	}

	return 0;
		
}



