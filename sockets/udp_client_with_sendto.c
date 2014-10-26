/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-12-26
    File        : udp_client_with_sendto.c
    Reference   : -
    Description : Client using UDP. sendto() function is used to transfer data to server.
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>       // memcpy
#include <arpa/inet.h>    // sockaddr
#include <errno.h>

#define APISERVER_IP   "127.0.0.1"
#define APISERVER_PORT 41000

struct sockaddr_in serverSocket;

// create socket
void UdpConnect(int* socketHandle, const char* hostAddress, int host_port) {

    int udpSocket;

    udpSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udpSocket < 0) {
        printf("Failed to create socket: %s", strerror(errno));
    }

    // generic container
    serverSocket.sin_family      = AF_INET;
    serverSocket.sin_addr.s_addr = inet_addr(hostAddress);
    serverSocket.sin_port        = htons(host_port);

    // connect to server
    connect(udpSocket, (struct sockaddr*)&serverSocket, sizeof(serverSocket));

    memcpy(&serverSocket, &serverSocket, sizeof(struct sockaddr));

    *socketHandle = udpSocket;
}


// send data
void SendRequest(int socketHandle, char* message) {

    int bytesWritten;

    // send bytes to server
    bytesWritten = sendto(socketHandle, message, strlen(message), 0, (struct sockaddr*)&serverSocket, sizeof(serverSocket));
    if (bytesWritten < 0) {
        printf("Unable to transmit request: %s", strerror(errno));
    }

    printf("Number of written bytes to server: %d\n",bytesWritten);
}


int main() {

    int udpSocket = 0;
    char* message = "ABCD";

    UdpConnect(&udpSocket,APISERVER_IP,APISERVER_PORT);
    SendRequest(udpSocket,message);

    close(udpSocket);

    return 0;
}
