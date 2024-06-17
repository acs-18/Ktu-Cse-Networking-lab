#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
int main()
{
    int n,s sock;
    struct sockaddr_in client,server;
    char b1[10]="",b2[10]="";
    s=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=3000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(s(struct sockaddr *)&server,&sizeof server);
    printf("\nEnter The file Name :");
    scanf("%s",b1);
    send(s,b1,sizeof(b1),0);
    while(1)
    {
        recv(s,b2,sizeof(b2),0);
        if(strcmp(b2,"-1")==0)
        {
            break;
        }
        else
        {
            printf("\nContents :");
        }
    }
        close(s);
        close(sock);
        return 0;
}