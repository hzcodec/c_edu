/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : udp_client2.c
    Reference   : 
    Description : 
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REMOTE_SERVER_PORT 1500
#define MAX_MSG 100


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int sd;
    int rc;
    int i;

    struct sockaddr_in cliAddr;
    struct sockaddr_in RemoteServAddr;
    struct hostent *h;

    if (argc < 3) {
        printf("usage: %s <server> <data1>\n",argv[0]);
	exit(1);
    }

    /* get server IP address */
    h = gethostbyname(argv[1]);

    if (h == NULL) {
        printf("%s: unknown host '%s'usage: %s \n",argv[0],argv[1]);
	exit(1);
    }

    
    printf("%s: sending data to '%s'usage: %s \n",argv[0],h->h_name;

    remoteServAddr.sin_family = h->h_addrtype;
    memcpy((char *) &remoteServAddr.sin_addr.s_addr,h->h_addr_list[0],h->h_length);
    remoteServAddr.sin_port = htons(REMOTE_SERVER_PORT);
    
    /* socket creation */
    sd = socket(AF_INET,SOCK_DGRAM),0);


    return 0;
}

/*
  Result from run:
*/

