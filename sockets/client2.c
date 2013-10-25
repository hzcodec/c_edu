/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : client2.c
    Reference   : See server2.c
    Description : Client program
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

    memset(recvBuff,'0',sizeof(recvBuff));

    if ((sockfd = socket(AF_INET,SOCK_STREAM, 0)) < 0) {
        printf("\n Error: could not create socket\n");
	return 1;
    } 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port   = htons(5000);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        printf("\n Error: Connect Failed\n");
	return 1;
    }

    while ((n=read(sockfd,recvBuff,sizeof(recvBuff)-1)) > 0) {
        recvBuff[n] = 0;
	if (fputs(recvBuff,stdout) == EOF) {
	    printf("\n Error: Fputs error\n");
	}
	printf("\n");
    }

    if (n<0) {
        printf("\n Read error\n");
    }

    return 0;
}

/*
  Result from run:
*/

