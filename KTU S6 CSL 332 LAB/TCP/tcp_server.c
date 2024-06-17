#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void main()
{
    struct sockaddr_in client,server;
    int s,n,sock;
    char b1[10]="",b2[10]="";
    s=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(s,(struct sockaddr *)&server,sizeof server);
    listen(s,1);
    n=sizeof client;
    sock=accept(s,(struct sockaddr *)&client,&n);
    for(;;)
    {
        recv(sock,b1,sizeof b1,0);
        if(strcmp(b1,"end")==0)
        break;
        printf("\nCLIENT: %s",b1);
        printf("\nSERVER :");
        scanf("%s",b2);
        send(sock,b2,sizeof b2,0);
        if(strcmp(b2,"end")==0)
        break;
    }
    close(sock);
    close(s);
}