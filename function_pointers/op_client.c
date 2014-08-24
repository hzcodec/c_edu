/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : udp_client.c
    Reference   : -
    Description : op_client is sending a command that corresponds to a function
                  in op_handler.

                  To run start server (op_handler) and then the client (op_client)
		    > ./op_client <operation> <value> <value>
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

#define REMOTE_SERVER_PORT 35000
#define IP_ADDRESS "127.0.0.1"


typedef struct {
    char operation[8];
    int  value1;
    int  value2;
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

    if (argc < 4) {
        printf("Error: To few in parameters (op_client <op> <val1> val2>).\n");
	exit(1);
    }

    // assign values
    strcpy(message1.operation,argv[1]);
    message1.value1 = strtol(argv[2],NULL,10); 
    message1.value2 = strtol(argv[3],NULL,10); 

    /* get server IP address */
    //h = gethostbyname("127.0.0.1");
    h = gethostbyname(IP_ADDRESS);

    printf("Sending data to server.\n");

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

    // bind port
    rc = bind(sd, (struct sockaddr *) &cliAddr, sizeof(cliAddr));

    if (rc < 0) {
        printf("%s: cannot bind port\n",argv[0]);
	exit(1);
    }

    /* send data */
    rc = sendto(sd, &message1, sizeof(message1), 0, (struct sockaddr*)&remoteServAddr, sizeof(remoteServAddr));

    if (rc < 0) {
        printf("%s: cannot send data %d\n",argv[0],i-1);
	close(sd);
	exit(1);
    }

    return 0;
}

