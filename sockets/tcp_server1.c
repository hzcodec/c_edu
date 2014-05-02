/*
    Auther      : Heinz Samuelsson
    Date        : 2014-05-02
    File        : udp_client1.c
    Reference   : Programming with sockets. Page 20.
                  The program creates a socket and then begins an
		  infinite loop. Each time through the loop it 
		  accepts a connection and prints data from it.
		  When the connection breaks, or the client closes
                  the connection, the program accepts a new connection.
*/

#include <stdio.h>
#include <stdlib.h>       // exit()
#include <sys/socket.h>
#include <arpa/inet.h>    // inet_addr
#include <sys/types.h>
#include <netdb.h>
#include <string.h>       // strlen

#define TRUE 1


int main(int argc , char *argv[]) {

    int    sock;
    int    length;
    struct sockaddr_in server;
    int    msgsock;
    char   buf[1024];
    int    rval;
 
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        perror("Opening stream socket");
        exit(1);
    }
         
    // Bind socket using wildcards
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(33000);
 
    if (bind(sock, (struct sockaddr*)&server, sizeof server) == -1) {
        perror("bindingstream socket");
        exit(1);
    }
     
    // Find out assigned port number and print it out
    length = sizeof server;
    if (getsockname(sock,(struct sockaddr*)&server,&length) == -1) {
        perror("Getting socket name");
        exit(1);
    }

    // network host to short
    printf("Socket port #%d\n",ntohs(server.sin_port));

    // Start accepting connections
    listen(sock,5);

    do {
        msgsock = accept(sock,(struct sockaddr*)0,(int*)0);

        if (msgsock == -1)
            perror("accept");

        else do {
            memset(buf, 0, sizeof buf);

            if ((rval = read(msgsock, buf, 1024)) == -1)
                perror("Reading stream message");
            if (rval == 0)
                printf("Ending connection\n");
            else
                printf("-->%s\n", buf);

         } while (rval != 0);

         close(msgsock);

     } while (TRUE);
  
    return 0;
}
