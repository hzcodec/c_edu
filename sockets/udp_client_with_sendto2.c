/*
    Auther      : Heinz Samuelsson
    Date        : 2014-12-26
    File        : udp_client_with_sendto.c
    Reference   : -
    Description : Client using UDP. sendto() function is used to transfer data to server.
                  A struct is transmitted as a message.
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>       // memcpy
#include <arpa/inet.h>    // sockaddr
#include <errno.h>

#define APISERVER_IP   "127.0.0.1"
#define APISERVER_PORT 41216

#define OUT(x, y, ...) printf("[" x "] (%s:%u): " y "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define INFO(x, ...)    OUT("INFO", x, ##__VA_ARGS__)
#define NOTICE(x, ...)  OUT("NOTICE", x, ##__VA_ARGS__)
#define WARNING(x, ...) OUT("WARNING", x, ##__VA_ARGS__)
#define ERROR(x, ...)   OUT("ERROR", x, ##__VA_ARGS__)
#define FATAL(x, ...)   OUT("FATAL", x, ##__VA_ARGS__)

// define structs
typedef struct {
    int  messageType;
    char transactionID[2];
    int  length;
} Command;

struct sockaddr_in serverSocket;

// create socket
void UdpConnect(int* socketHandle, const char* hostAddress, int host_port) {

    INFO("ENTER: %s()", __func__);

    int udpSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udpSocket < 0) {
        ERROR("Failed to create socket: %s", strerror(errno));
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
void SendRequest(int* socketHandle, Command* cmd) {

    NOTICE("ENTER: %s()", __func__);

    // send message to server
    int bytesWritten = sendto(*socketHandle, cmd, sizeof(*cmd), 0, (struct sockaddr*)&serverSocket, sizeof(serverSocket));
    if (bytesWritten < 0) {
        ERROR("Unable to transmit request: %s", strerror(errno));
    }

    printf("Number of written bytes to server: %d\n",bytesWritten);
}


int main() {

    int  udpSocket = 0;
    char ch;

    Command cmd;
    cmd.messageType   = 10;
    cmd.length        = 30;
    strcpy(cmd.transactionID,"AB");

    UdpConnect(&udpSocket,APISERVER_IP,APISERVER_PORT);

    // send messages until 'q' is entered
    while (ch != 'q') {
        SendRequest(&udpSocket,&cmd);

        ch = getchar();
        INFO("Received event: %c", ch);

        cmd.messageType += 1;
    }
}
