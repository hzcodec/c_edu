/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-12-26
    File        : udp_server_with_sendto.c
    Reference   : -
    Description : Server using UDP. read() function is used to receive data.
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>   // sockaddr()
#include <unistd.h>      // read()

#define APISERVER_IP   "127.0.0.1"
#define APISERVER_PORT 41000

int main() {

    int serverSocket;
    int n;             // number of received bytes
    char buff[20];

    // define socket descriptor
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // server address, address of the machine
    struct sockaddr_in serverAddress;

    // generic container
    serverAddress.sin_family      = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(APISERVER_IP);
    serverAddress.sin_port        = htons(APISERVER_PORT);

    // bind the socket, associate and reserves a port for use by the socket
    bind(serverSocket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));

    // loop for ever and ever
    for (;;) {
        printf("\nWaiting for data to be received ->\n");
        n = read(serverSocket,buff,20);
        printf("Number of received data: %d\n",n);

        for (int i=0; i<n; i++) {
            printf("Received data: %c\n",buff[i]);
        }
    }

    return 0;
}
