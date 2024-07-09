#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#define MAX_FRAME 100

int main()
{
    printf("WAITING FOR CLIENT : \n");
    
    struct sockaddr_in servaddr, cliaddr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    int len = sizeof(cliaddr);
    int frames[MAX_FRAME];
    int n;

    // Receive total number of frames from client
    recvfrom(sockfd, &n, sizeof(n), 0, (struct sockaddr *)&cliaddr, &len);
    printf("\nClient Connected Successfully....!\n");
    printf("\nWaiting For Total Number Of Frames...\n");

    int p, ack;
    while (1) {
        recvfrom(sockfd, &p, sizeof(p), 0, (struct sockaddr *)&cliaddr, &len);
        
        if (p == -99)
            break;

        printf("\nReceived Frame: %d\n", p);
        printf("\nEnter 1 for Positive ACK or -1 for Negative ACK: ");
        scanf("%d", &ack);
        sendto(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    }

    close(sockfd);
    return 0;
}