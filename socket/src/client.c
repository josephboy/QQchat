#include "client.h"
#include "pthread.h" 

#define SERVER_IP "127.0.0.1"
#define PORT 8080


int ClientInit(void)
{
    unsigned short port = PORT;
    char *server_ip = SERVER_IP;
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > sockfd)
    {
        perror("client socket create failed\n");
        exit(-1);
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    int ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (0 != ret)
    {
        perror("client connect failed\n");
        close(sockfd);
        exit(-1);
    }
    return sockfd;
}

void *ClientSendMsg(void *clifd)
{
    int fd = *(int *)clifd;
    char send_buf[512] = "";
    while (1)
    {
        fgets(send_buf, sizeof(send_buf), stdin);/*接收sizeof(send_buf) - 1个字符，会自动在最后一个位置加'\0'*/
        send(fd, send_buf, strlen(send_buf), 0);
    }
    close(fd);
    
}


void *ClientGetMsg(void *clifd)
{
    int fd = *(int *)clifd;
    char rcv_buf[512] = "";
    while (1)
    {
        printf("%s:%d\n", __func__, fd);
        sleep(1);
    }

}


int main(void)
{
    pthread_t p_recv;
    pthread_t p_send;

    int clifd = ClientInit();
    pthread_create(&p_recv, NULL, ClientGetMsg, &clifd);
    pthread_create(&p_send, NULL, ClientSendMsg, &clifd);


    return 0;
}
