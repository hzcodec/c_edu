/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-12-26
    File        : udp_server_with_sendto.c
    Reference   : -
    Description : Server using UDP. read() function is used to receive data.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>       // memcpy
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>   // sockaddr()
#include <unistd.h>      // read()
#include <errno.h>

#define APISERVER_IP   "127.0.0.1"
#define APISERVER_PORT 41216


typedef struct {
    int     messageType;
    char    transactionID[2];
    int     length;
} Command;


int main() {

    int     serverSocket;
    int     n;
    Command rec_cmd;

    // define socket descriptor
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // server address, address of the machine
    struct sockaddr_in serverAddress;

    serverAddress.sin_family      = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(APISERVER_IP);
    serverAddress.sin_port        = htons(APISERVER_PORT);

    bind(serverSocket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));


    // loop for ever and ever
    for (;;) {
        printf("\nWaiting for data to be received ->\n");
        printf("==================================\n");

        n = read(serverSocket,&rec_cmd,sizeof(rec_cmd));

        printf("Number of received data: %d\n",n);
        printf("Message type:    %d\n",rec_cmd.messageType);
        printf("Transaction ID:  %s\n",rec_cmd.transactionID);
        printf("Length:          %d\n",rec_cmd.length);
    }

    return 0;
}
