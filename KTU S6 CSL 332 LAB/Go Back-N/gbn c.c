#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    printf("Searching for Server...\n");
    
    struct sockaddr_in servaddr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n = -1;
    sendto(sockfd, &n, sizeof(n), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("\nServer Found and Connected Successfully..\n");
    printf("\nEnter The Total Number Of Frames: ");
    scanf("%d", &n);
    sendto(sockfd, &n, sizeof(n), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    int len, ack;
    for (int i = 1; i <= n; i++) {
        ack = -1;
        do {
            printf("\nSending Frame: %d\n", i);
            sendto(sockfd, &i, sizeof(i), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
            printf("\nWaiting For ACK..\n");
            recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&servaddr, &len);
            if (ack == -1) {
                printf("\nNegative ACK Received... Resending Frame %d..\n", i);
            }
        } while (ack == -1);
    }

    n = -99;
    sendto(sockfd, &n, sizeof(n), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("\nSuccessfully Sent all the Frames.\n");

    close(sockfd);
    return 0;
}