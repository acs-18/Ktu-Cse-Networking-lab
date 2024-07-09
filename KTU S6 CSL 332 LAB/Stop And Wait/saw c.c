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
    printf("Searching for Client...\n");
    struct sockaddr_in servaddr;
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    memset(&servaddr,0,sizeof servaddr);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(2000);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    int n=-1;
    sendto(sockfd,&n,sizeof n,0,(struct sockaddr *)&servaddr,sizeof servaddr);
    printf("\nServer Connected Successfully..\n");
    printf("\nEnter The Total No Of Frames...\n");
    scanf("%d",&n);
    sendto(sockfd,&n,sizeof n,0,(struct sockaddr *)&servaddr,sizeof servaddr);
    int len,ack;
    for(int i = 1;i<=n ; i++)
    {
        ack=-1;
        do
        {
            printf("\nSending Frames : %d",i);
            sendto(sockfd,&i,sizeof n,0,(struct sockaddr *)&servaddr,sizeof servaddr);
            printf("\nWaiting For ACK..\n");
            recvfrom(sockfd,&ack,sizeof n ,0,(struct sockaddr *)&servaddr,&len);
            if(ack==-1)
            {
                printf("\nNegative ACK Recived... Resending..\n");
            }
        }
        while(ack==-1);
    }
    n=-99;
    sendto(sockfd,&n,sizeof n,0,(struct sockaddr *)&servaddr,sizeof servaddr);
    printf("\nSuccessfullly Sent all the Frames  :");
    close(sockfd);
    return 0;
}