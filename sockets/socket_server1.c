/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-04
    File        : socket_server1.c
    Reference   : -
    Description : UDP server. Receiving a struct.
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOCAL_SERVER_PORT 1500


typedef struct {
    int a;
    char b[8];
} data_message;


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int sd;
    int rc;
    int n;
    int cliLen;

    struct sockaddr_in cliAddr;
    struct sockaddr_in servAddr;
    data_message rec_message;

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
	memset(&rec_message,0x0,sizeof(rec_message));

        /* receive message */
        cliLen = sizeof(cliAddr);
	n = recvfrom(sd,
                     &rec_message,
		     sizeof(rec_message),
		     0,
		     (struct sockaddr *)&cliAddr,
		     &cliLen
		     );

	if (n < 0) {
            printf("%s: cannot receive data %d\n",argv[0]);
	    continue;
	}

	/* print received message */
	printf("rec_message: %d\n",rec_message.a);
	printf("rec_message: %s\n",rec_message.b);
    }

    return 0;
}

