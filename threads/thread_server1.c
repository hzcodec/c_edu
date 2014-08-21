/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-25
    File        : thread_server1.c
    Reference   : 
    Description : The program is receiving data/string from client. Use thread_client1.c.
                  The server is returning the received string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


// each command corresponds to an index
int get_message_idx(char* msg) {

    if (strcmp(msg,"run") == 0) {
        return 0;
    }
    else if (strcmp(msg,"stop") == 0) {
        return 1;
    }
    else {
      return 2; // invalid command
    }
}


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    // declarations
    int sockfd;
    int n;
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
    socklen_t len;
    char mesg[1000];
    int idx = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM,0);

    memset(&servaddr,sizeof(servaddr),0);

    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(32003);
    bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

    // infinit loop until stop command is received
    while (idx != 1) {

        len = sizeof(cliaddr);

        // return value is the number of bytes
        n  = recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);

        // send back info to client
        sendto(sockfd,mesg,n,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
        mesg[n-1] = '\0';
        printf("Received command: %s\n",mesg);

        // get index of the received message, used by switch statement
        idx = get_message_idx(mesg);

        switch (idx) {
            case 0:   printf("*** Run command sent\n");     break;
            case 1:   printf("*** Stop command sent\n");    break;
            default : printf("*** Invalid command sent\n"); break;
        }

        printf("---------------------\n");
    }

    printf("Server is closed\n");
    close(sockfd);

    return 0;
}

