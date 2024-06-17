#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/tpes.h>
#include<sys.socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int ispalindrome(char *num)
{
    int len = strlen(num);
    int i,j;
    for(i=0;j=len-1;i<j;i++,j++)
    {
        if(num[i] !=num[j])
        {
            return 0;
        }
    }
    return 1;
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
        printf("\nClient : %s",b1);
        if(ispalindrome(b1))
            printf(b2,sizeof(b2),"palindrome");
        else
            printf(b2,sizeof(b2),"Not a Palindrome");
        printf("\nServer :");
        scanf("%s",b2);
        send(sock,b2,sizeof b2,0);
        if(strcmp(b2,"end")==0)
            break;
    }
    close(s);
    close(sock);
    return 0:
}
