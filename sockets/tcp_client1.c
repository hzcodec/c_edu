/*
    Auther      : Heinz Samuelsson
    Date        : 2014-05-02
    File        : udp_client1.c
    Reference   : Programming with sockets. Page 20.

                  The program creates a socket and initiates a 
		  connection with the socket given in the command line.
		  Some data are sent over the connection and then the
		  socket is closed, ending the connection.
                  The form of the command line is: tcp_client1 <ip_address> <port_number>
                      > ./tcp_client1 127.0.0.1 33000


	+------------------+                +-------------------+
	|                  |   DATA         |                   |
	|   tcp_client1    |--------------->|    tcp_server1    |
	|                  |                |                   |
	|   socket(...)    |                |    socket(...)    |
	|   connect()      |                |    bind()         |
	|   write()        |                |    listen()       |
	|                  |                |    accept()       |
	|                  |                |    read()         |
	|                  |                |                   |
	+------------------+                +-------------------+


	          Associate a socket with a port on your local machine.
	              bind(int sockfd, struct sockaddr *my_addr, int addrlen)
		  Connect to a remote host - then use accept() then use accept()
                      listen(int sockfd, int backlog)
		  Accept new connection request from a client.
		      accept(int sockfd, struct sockaddr addr*, socklen_t *addrlen) 
*/

#include <stdio.h>
#include <stdlib.h>      // exit()
#include <string.h>      // strlen
#include <sys/socket.h>
#include <arpa/inet.h>   // inet_addr
#include <sys/types.h>
#include <netdb.h>
 
#define DATA "Jennie Samuelsson, Brunstorps Hage 55"


int main(int argc , char *argv[]) {

    int    sock;
    struct sockaddr_in server;
    struct hostent *hp;
    char   buf[1024];
 
    // create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        perror("Opening stream socket");
        exit(1);
    }
         
    // connect socket using name specified by command line
    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);
    printf("hp name: %s\n",hp->h_name);
 
    // gethostbyname() returns a structure including the network
    // address of the specified host
    if (hp == (struct hostent*)0) {
        fprintf(stderr,"%s: unknown host\n",argv[1]);
        exit(2);
    }

    memcpy((char*)&server.sin_addr, (char*)hp->h_addr, hp->h_length);
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sock,(struct sockaddr*)&server, sizeof server)== -1) {
        perror("Connecting to stream socket");
        exit(1);
    }

    if (write(sock,DATA,sizeof DATA) == -1)
        perror("Writing on stream socket"); 
 
    close(sock);
     
    return 0;
}
