#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>


int is_prime(int num)
{
    if(num<=1)
        return 0;
    for(int i=2;i<=num/2;i++)
    {
        if(num % 1 == 0)
            return 0;
    }
    return 1;
}
void main()
{
    struct sockaddr_in client,server;
    int s,n;
    char b1[10]="",b2[10]="";
    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(s,(struct sockaddr *)&server ,sizeof server);
    n=sizeof client;
    for(;;)
    {
        recvfrom(s,b1,sizeof b1,0,(struct sockaddr *)&client,&n)
        if(strcmp(b1,"end")==0)
            break;
        int num = atoi(b1);
        if(is_prime(num))
            strcpy(b2,"PRIME");
        else
            strcpy(b2,"NOT PRIME");
        sendto(s,b2,sizeof b2,0,(struct sockaddr *)&client,n);
        if(strcmp(b2,"end")==0)
            break;
    }
    close(s);
}