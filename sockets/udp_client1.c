/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : udp_client1.c
    Reference   : See server1.c
    Description : Client program. Start program and enter text.
                  To communicate locally (localhost) -
                      > ./udp_client 127.0.0.1
		  or with another computer in the network -
                      > ./udp_client 192.168.1.69
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int sockfd;
    int n;
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;

    char sendline[1000];
    char recvline[1000];

    if (argc!= 2) {
        printf("usage: udpcli <IP address>\n");
	exit(1);
    }

    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port        = htons(32000);

    while (fgets(sendline,10000,stdin) != NULL) {
        sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	n = recvfrom(sockfd,recvline,10000,0,NULL,NULL);
	recvline[n] = 0;
	fputs(recvline,stdout);
    }

    return 0;
}

/*
  Result from run:
*/

