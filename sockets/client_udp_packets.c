/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-08-31
    File        : client_udp_packets.c
    Reference   : -
    Description : Client.

                   struct sockaddr_in {
                       short            sin_family;   // e.g. AF_INET
                       unsigned short   sin_port;     // e.g. htons(3490)
                       struct in_addr   sin_addr;     // see struct in_addr, below
                       char             sin_zero[8];  // zero this if you want to
                   };

                   struct in_addr {
                       unsigned long s_addr;  // load with inet_aton()
                   };
};

 
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
#define PORT   9930
#define NPACK  10
#define SRV_IP "127.0.0.1"

void diep(char *s) {
    perror(s);
    exit(1);
}


/* *** MAIN *** */
int main() {

    // declarations
    struct sockaddr_in si_other;  // server address
    int  sockfd;
    int  i;
    int  slen = sizeof(si_other);
    char buf[BUFLEN];
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
        diep("socket");
    
    // not necessary
    memset((char *) &si_other, 0, sizeof(si_other));

    si_other.sin_family = AF_INET;
    si_other.sin_port   = htons(PORT);

    if (inet_aton(SRV_IP, &si_other.sin_addr) == 0) {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }
 
    for (i=0; i<NPACK; i++) {
        printf("Sending packet %d\n", i);
        sprintf(buf, "This is packet %d\n", i);
        if (sendto(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&si_other, slen) == -1)
            diep("sendto()");
    }
 
    close(sockfd);
    return 0;
}
