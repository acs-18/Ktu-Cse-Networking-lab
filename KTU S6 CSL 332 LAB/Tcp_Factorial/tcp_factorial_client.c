#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void disPalindrome(const char *num,const char *result)
{
    printf("Number '%s' is %s.\n",num,result);
}
void main()
{
    struct sockaddr_in client,server;
    int s,n,sock;
    char b1[10]=" ",b2[10]=" ";
    s=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(s,(struct sockaddr *)&server,sizeof server);
    for(;;)
    {
        printf("\nEnter a number to calculate factorial (or 'end' to exit): ");
        scanf("%s", b2);

        send(s,b2,sizeof b2,0);
        if(strcmp(b2,"end")==0)
        break;
          char b1[20];
        recv(s, b1, sizeof(b1), 0);

        // Display factorial result
        printf("Factorial of %s is: %s\n", b2, b1);
        if(strcmp(b1,"end")==0)
        break;
        disPalindrome(b2,b1);
        printf("\nServer : %s",b1);
    }
    close(s);
}