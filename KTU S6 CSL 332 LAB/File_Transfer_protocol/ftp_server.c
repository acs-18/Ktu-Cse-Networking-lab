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
    int n,s,sock,i;
    FILE *f;
    struct sockaddr_in client,server;
    char b1[20]="",b2[20]="";
    s=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=3000;
    server.sin_addr.s_addr=inet_addr("127,0,0,1");
    bind(s(struct sockaddr *)&server,&sizeof server);
    listen(s,1);
    n=sizeof client;
    sock=accept(s,(struct sockaddr *)&client,&n);
    recv(sock,b1,sizeof(b1),0);
    printf("\nFILENAME :%s",b1);
    f=fopen(b1,"r");
    if(f!=NULL)
    {
        while(fgets(b2,sizeof (b2),f)!=NULL)
        {
            printf("\nContents :%s",b2);
            send(sock,b2,sizeof(b2),0);
        }
        send(sock,"-1",sizeof ("-1"),0);
    }
    else
    {
        printf("\nFile Not Exist :");
    }
    return 0;
}