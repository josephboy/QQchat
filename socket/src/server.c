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
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

	int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (0 != ret)
	{
		perror("server bind failed\n");
		close(sockfd);
		exit(-1);
	}

	ret = listen(sockfd, 10);
	if (0 != ret)
	{
		perror("server listen failed\n");
		close(sockfd);
		exit(-1);
	}

	return sockfd;
		
}

void ServerConnectClient(int Sockfd)
{
	struct sockaddr_in client_addr;
	socklen_t cliadrr_len = sizeof(client_addr);
	char cli_ip[INET_ADDRSTRLEN] = "";

	while (1)
	{
		int connfd = accept(Sockfd, (struct sockaddr*)&client_addr, &cliadrr_len);
		if (0 > connfd)
		{
			perror("server connect failed\n");
			continue;
		}
		inet_ntop(AF_INET, &client_addr.sin_addr, cli_ip, INET_ADDRSTRLEN);
		char recv_buf[512] = "";
		/*recv先检查发送缓冲区是否为空，再检查接收缓冲区是否为空*/
		while (recv(connfd, recv_buf, sizeof(recv_buf), 0) > 0)
		{
			printf("recv data(%s):%s\n", cli_ip, recv_buf);
		}
		close(connfd);
		printf("client(%s) closed!\n", cli_ip);
	}
	close(Sockfd);
}	


void main(void)
{
	int sockfd = server_init();
	ServerConnectClient(sockfd);
}



