#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{
    struct sockaddr_in server,client;
    int s,i,n,sock;
    FILE *f;
    char b1[10]="",b2[10]="";
    s=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(s,(struct sockaddr *)&server,sizeof server);
    listen(s,1);
    n=sizeof client;
    sock=accept(s,(struct sockaddr *)&client,&n);
    recv(sock,b1,sizeof b1,0);
    printf("\nFileName : %s",b1);
    f=fopen(b1,"r");
    if(f!=NULL)
    {
        while(fgets(b2,sizeof b2,f)!=NULL)
        {
            prinf("\nCONTENTS :%s",b2);
            send(sock,b2,sizeof b2,0);
        }
        send(sock,"-1"sizeof "-1",0);
    }
    else
    {
        printf("File Not Exist : ");
    }
}