#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
    struct sockaddr_in client,server;
    int s,sock,n;
    char b1[10]="",b2[10]="";
    s=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    n=sizeof server;
    while(1)
    {
        printf("\nCIENT :");
        scanf("%s",b2);
        sendto(s,b2,sizeof b2,0,(struct sockaddr *)&server,n);
        if(!strcmp(b2,"end")==0)
        break;
        recvfrom(s,b1,sizeof b1,0,NULL,NULL);
        printf("\n SERVER : %s",b1);
    }
}
