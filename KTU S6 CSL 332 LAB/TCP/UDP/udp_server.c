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
    serevr.sin_port=3000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(s,(struct sockaddr *)&server,sizeof server);
    n=sizeof client;
    while(1)
    {
        recvfrom(s,b1,sizeof b1,0,(struct sockaddr *)&client,&n);
        if(strcmp(b1,"end")==0)
        {
            break;
        }
        printf("\nCLIENT : %s",b1);
        printf("\nSERVER  :");
        fgets(b2,sizeof (b2),stdin);
        b2[strcspn(b2,"\n")]='\0';
        sendto(s,b2,sizeof b2,0,(struct sockaddr *)&client,n);
        if(strcmp(b2,"end")==0)
        {
            break;
        }
    }
}