/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : udp_server2.c
    Reference   : www.it.uom.gr/project/client_server/socket/socket
    Description : UDP server.
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL_SERVER_PORT 1500
#define MAX_MSG 100


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int sd;
    int rc;
    int n;
    int cliLen;

    struct sockaddr_in cliAddr;
    struct sockaddr_in servAddr;
    char msg[MAX_MSG];

    /* create a socket */
    sd = socket(AF_INET, SOCK_DGRAM,0);
    if (sd < 0) {
        printf("%s: cannot open socket\n",argv[0]);
	exit(1);
    }

    /* bind local server port */
    servAddr.sin_family      = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port        = htons(LOCAL_SERVER_PORT);

    rc = bind(sd,(struct sockaddr *)&servAddr,sizeof(servAddr));
    if (rc < 0) {
        printf("%s: cannot bind port number %d\n",argv[0],LOCAL_SERVER_PORT);
	exit(1);
    }

    printf("%s: waiting for data on port UDP %u\n",argv[0],LOCAL_SERVER_PORT);

    while(1) {
	
	/* init buffer */
	memset(msg,0x0,MAX_MSG);

        /* receive message */
        cliLen = sizeof(cliAddr);
	n = recvfrom(sd,msg,MAX_MSG,0,(struct sockaddr *)&cliAddr,&cliLen);
	if (n < 0) {
            printf("%s: cannot receive data %d\n",argv[0]);
	    continue;
	}

	/* print received message */
	printf("%s: from %s:UDP%u : %s \n",argv[0],inet_ntoa(cliAddr.sin_addr),ntohs(cliAddr.sin_port),msg);
    }

    return 0;
}

/*
  Result from run:
*/

