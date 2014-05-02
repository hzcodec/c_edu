/*
    Auther      : Heinz Samuelsson
    Date        : 2014-05-02
    File        : tcp_server2.c
    Reference   : Programming with sockets. Page 27.
    Description : How to run:
                    > ./tcp_server2 hello 127.0.0.1 33000
*/

#include <stdio.h>
#include <stdlib.h>      // exit()
#include <sys/socket.h>
#include <arpa/inet.h>   //inet_addr
#include <sys/types.h>
#include <netdb.h>
#include <string.h>      //strlen

#define DATA "Mattias Samuelsson, Brunstorps Hage 55" 

// send a datagram to a receiver whose name is gotten from command line
int main(int argc , char *argv[]) {

    int sock;
    struct sockaddr_in name;
    struct hostent *hp;
 
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        perror("Opening datagram socket");
        exit(1);
    }
         
    hp = gethostbyname(argv[1]);
    if (hp == (struct hostent*)0) {
        fprintf(stderr, "%s: unknown host\n",argv[1]);
        exit(2);
    }

    memcpy((char*)&name.sin_addr, (char*)hp->h_addr,hp->h_length);
    name.sin_family = AF_INET; 
    name.sin_port = htons(atoi(argv[2]));

      
    if (sendto(sock, DATA, sizeof DATA, 0, (struct sockaddr*)&name, sizeof name) == 1)
        perror("sending datagram message");
 
    close(sock);
   
    return 0;
}
