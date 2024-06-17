#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
void main()
{
    struct sockaddr_in client,server;
    int s,sock,n;
    char b1[10]="",b2[10]="";
    s=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=3000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    n=sizeof server;
    while(1)
    {
        printf("\nCLIENT :");
        fgets(b2,sizeof (b2),stdin);
        b2[strcspn(b2,"\n")]='\0';
        sendto(s,b2,sizeof b1,0,NULL,NULL);
        printf("\nSERVER : %s ",b1);
        if(strcmp(b1,"end")==0)
        {
            break;
        }
    }
}