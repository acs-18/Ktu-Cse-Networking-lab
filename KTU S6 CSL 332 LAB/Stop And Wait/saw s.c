#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    printf("WAITING FOR CLIENT : \n");
    struct sockaddr_in servaddr,cliaddr;
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    memset(&servaddr,0,sizeof servaddr);
    memset(&cliaddr,0,sizeof cliaddr);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(2000);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd,(const struct sockaddr *)&servaddr,sizeof servaddr);
    int len = sizeof cliaddr;
    int frames[100],n;
    recvfrom(sockfd,&n,sizeof n,0,(struct sockaddr *)&cliaddr,&len);
    printf("\nClient Connected Successfully....!\n");
    printf("\nWaiting For Total Number Of Frames...\n");
    recvfrom(sockfd,&n,sizeof n,0,(struct sockaddr *)&cliaddr,&len);
    int p,ack;
    while(1)
    {
        recvfrom(sockfd,&p,sizeof n,0,(struct sockaddr *)&cliaddr,&len);
        if(p==-99)
            return 0;
        printf("\nReceived From : %d",p);
        printf("\n Enter 1 For +ve ACK OR -1 For -ve ACK..");
        scanf("%d",&ack);
        sendto(sockfd,&ack,sizeof n,0,(struct sockaddr *)&cliaddr,sizeof cliaddr);
    }
    return 0;
}

