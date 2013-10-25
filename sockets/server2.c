/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : server2.c
    Reference   : codeproject.com/Articles/586000/Networking-and-Socket-programming-tutorial-in-C
    Description : Server program. 
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
int main(void) {

    int    listenfd = 0;
    int    connfd   = 0;
    struct sockaddr_in serv_addr;

    char   sendBuff[1025];
    int    numrv;

    listenfd = socket(AF_INET,SOCK_STREAM, 0);
    printf("Socket retreive success\n");

    memset(&serv_addr,'0',sizeof(serv_addr));
    memset(sendBuff,'0',sizeof(sendBuff));

    serv_addr.sin_family      = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port        = htons(5000);

    bind(listenfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if (listen(listenfd,10) == -1) {
        printf("Failed to listen\n");
    }

    while(1) {
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	strcpy(sendBuff,"Message from server");
	write(connfd,sendBuff,strlen(sendBuff));

	close(connfd);
	sleep(1);
    }

    return 0;
}

/*
  Result from run:
*/

