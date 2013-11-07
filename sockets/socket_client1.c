/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-04
    File        : socket_client1.c
    Reference   : -
    Description : UDP client. Sending a struct.

                  To run start client and server (socket_server1) -
		    > ./udp_client3 127.0.0.1 99
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#define REMOTE_SERVER_PORT 1500


typedef struct {
    int a;
    char b[8];
} data_message;


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int    sd;
    int    rc;
    int    i;
    struct sockaddr_in cliAddr;
    struct sockaddr_in remoteServAddr;
    struct hostent *h;
    data_message message1;


    if (argc < 3) {
        printf("Error: Add server address and data.\n");
	exit(1);
    }

    // assigne values to the struct, since argv[2] is a string convert to int is needed
    message1.a = strtol(argv[2],NULL,10); 
    strcpy(message1.b,"Jennie");

    /* get server IP address */
    h = gethostbyname(argv[1]);

    if (h == NULL) {
        printf("%s: unknown host '%s'usage: %s \n",argv[0],argv[1]);
	exit(1);
    }

    
    printf("%s: sending data to '%s' (IP : %s)\n",argv[0],h->h_name,inet_ntoa(*(struct in_addr *)h->h_addr_list[0]));


    remoteServAddr.sin_family = h->h_addrtype;
    memcpy((char *) &remoteServAddr.sin_addr.s_addr,h->h_addr_list[0],h->h_length);
    remoteServAddr.sin_port = htons(REMOTE_SERVER_PORT);
    
    /* socket creation */
    sd = socket(AF_INET,SOCK_DGRAM,0);

    if (sd < 0) {
        printf("%s: cannot open socket\n",argv[0]);
	exit(1);
    }

    /* bind any port */
    cliAddr.sin_family      = AF_INET;
    cliAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    cliAddr.sin_port        = htons(0);

    //        file descriptor
    //             pointer to sockaddr structure
    //                                             length
    rc = bind(sd, (struct sockaddr *) &cliAddr, sizeof(cliAddr));

    if (rc < 0) {
        printf("%s: cannot bind port\n",argv[0]);
	exit(1);
    }

    int j;
    for (j=0; j<5; j++) {
        /* send data */
        rc = sendto(sd,
                    &message1,
                    sizeof(message1),
            	    0,
            	    (struct sockaddr*)&remoteServAddr,
            	    sizeof(remoteServAddr)
                    );

        if (rc < 0) {
            printf("%s: cannot send data %d\n",argv[0],i-1);
            close(sd);
            exit(1);
        }

	message1.a = message1.a + 33;

	// just wait a while to simulate processing of data
	sleep(2);
    }

    return 0;
}

