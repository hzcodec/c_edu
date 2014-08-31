/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-08-31
    File        : server_udp_packets.c
    Reference   : -
    Description : Server.
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define BUFLEN 512
#define NPACK  10
#define PORT   9930

void diep(char *s) {
    perror(s);
    exit(1);
}


/* *** MAIN *** */
int main() {

    struct sockaddr_in si_me;
    struct sockaddr_in si_other;
    char buf[BUFLEN];
    int sockfd;
    int i;
    int slen = sizeof(si_other);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        diep("socket"); 

    memset(&si_me,'0',sizeof(si_me));

    si_me.sin_family = AF_INET;

    // byte order is correct, Host TO Network order/Short integer 
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr*)&si_me, sizeof(si_me))==-1)
        diep("bind");

    for (i=0; i<NPACK; i++) {
        if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&si_other, &slen)==-1)
            diep("recvfrom()");

        printf("Received packet from %s:%d\nData: %s\n\n", 
                inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
    }
    
    close(sockfd);
    return 0;
}
