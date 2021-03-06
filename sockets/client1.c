/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : client1.c
    Reference   : http://www.thegeekstuff.com/2011/12/c-socket-programming
    Description : The client is receiving the date and time. The server must
                  be up and running before the client starts.
		  To run:
		    1) > ./server1
		    2) > ./client1 127.0.0.1
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int    sockfd = 0;
    int    n = 0;
    char   recvBuff[1024];
    struct sockaddr_in serv_addr;

    if (argc != 2) {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
	return 1;
    }

    memset(recvBuff,'0',sizeof(recvBuff));

    if ((sockfd = socket(AF_INET,SOCK_STREAM, 0)) < 0) {
        printf("\n Error: could not create socket\n");
	return 1;
    } 

    memset(&serv_addr,'0',sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port   = htons(5000);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("\n inet_pton error occured\n");
    }

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        printf("\n Error: Connect Failed\n");
	return 1;
    }

    while ((n=read(sockfd,recvBuff,sizeof(recvBuff)-1)) > 0) {
        recvBuff[n] = 0;
	if (fputs(recvBuff,stdout) == EOF) {
	    printf("\n Error: Fputs error\n");
	}
    }

    if (n<0) {
        printf("\n Read error\n");
    }

    return 0;
}

/*
  Result from run:
*/

