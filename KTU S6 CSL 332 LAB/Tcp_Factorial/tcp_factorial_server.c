#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>


int factorial(int num) 
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}
int main()
{
    struct sockaddr_in client,server;
    int sock,s,n;
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
        int num = atoi(b1);
        int result = factorial(num);
        printf("\nClient : %s",b1);
        char response[20];
        snprintf(response, sizeof(response), "%d", result);
        send(sock, response, sizeof(response), 0);
        printf("\nServer :");
        scanf("%s",b2);
        if(strcmp(b2,"end")==0)
            break;
    }
    close(s);
    close(sock);
    return 0;
}
