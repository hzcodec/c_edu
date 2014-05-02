/*
    Auther      : Heinz Samuelsson
    Date        : 2014-05-02
    File        : tcp_client2.c
    Reference   : Programming with sockets. Page 27.
    Description : Not working!!
*/

#include <stdio.h>
#include <stdlib.h>      // exit()
#include <string.h>      //strlen
#include <sys/socket.h>
#include <arpa/inet.h>   //inet_addr
#include <sys/types.h>
#include <netdb.h>
 

int main() {

    int sock;
    int length;
    struct sockaddr_in name;
    char buf[1024];
 
    // create socket from which to read
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        perror("opening datagram socket");
        exit(1);
    }
         
    // create name with wildcards
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = INADDR_ANY;
    name.sin_port = htons(33000);

    if (bind(sock, (struct sockaddr*)&name, sizeof name) == -1) {
        perror("binding datagram socket");
        exit(1);
    }

    // find assigned port value and print it out
    length = sizeof(name);
    if (getsockname(sock, (struct sockaddr*)&name, &length) == -1) {
        perror("getting socket name");
        exit(1);
    }

    printf("Socket port #%d\n",ntohs(name.sin_port));

    if (read(sock, buf, 1024) == -1)
        perror("receiving datagram packet");

    printf("-->%s\n",buf);
    close(sock);

    return 0;
}
