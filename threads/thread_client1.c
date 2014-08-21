/*
    Auther      : Heinz Samuelsson
    Date        : 2014-08-17
    File        : thread_client1.c
    Reference   : See thread_server1.c
    Description : Client program. Start program and enter text.

                  Create two threads. One is only counting up a global variable.
                  The other one is sending messages via UDP.
                  To communicate locally (localhost) -

                      > ./thread_client1 127.0.0.1
                  or with another computer in the network -
                      > ./thread_client1 192.168.1.69
                  The server interprets the sent commands.
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>  // pthread functions and data structures

static int counter_value = 0;

// dummy function for thread
//void *count_up() {   // use this with pthread_create(...(void*)count_up...) instead.
void count_up() {

    while(1) {
        sleep(2);
        printf("Counter value: %d\n",counter_value++);
    }
}


// handle commands that are sent via UDP
void send_command(void* addr) {

    int sockfd;
    int n;
    struct sockaddr_in servaddr;
    char   sendline[1000];
    char   recvline[1000];

    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    memset(&servaddr,sizeof(servaddr),0);
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(addr);
    servaddr.sin_port        = htons(32003);

    while (fgets(sendline,10000,stdin) != NULL) {
        printf("Client sent: ");
        sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
        n = recvfrom(sockfd,recvline,10000,0,NULL,NULL);
        recvline[n] = 0;
        fputs(recvline,stdout);
    }
}


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    pthread_t thread_id1;
    pthread_t thread_id2;

    if (argc!= 2) {
        printf("usage: thread_client1 <IP address>\n");
        exit(1);
    }

    // create threads, one is counting up the other is handling commands
    //pthread_create(&thread_id1,NULL,(void*)count_up,NULL);
    pthread_create(&thread_id1,NULL,(void*)&count_up,NULL);
    pthread_create(&thread_id2,NULL,(void*)&send_command,(void*)(argv[1]));

    // infinity loop
    for (;;);

    return 0;
}

