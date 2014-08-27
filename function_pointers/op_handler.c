/*
    Auther      : Heinz Samuelsson
    Date        : 2014-08-21
    File        : op_handler.c
    Reference   : -
    Description : op_handler is receiving message from op_client.
                  The message is checked and matching function is
                  called, which in turn is calling the correponding 
                  function in operations.c.

                  A server is implemented to handle the incomming message.

                  How to run the program:
                    > ./op_handler 
                    > ./op_client <operation> <value1> <value2>

                  Ex:
                    > ./op_handler 
                    > ./op_client add 5 6

                  Result:
                    Waiting for message to be received from client ...
                    ------------------------------------
                    Received the following from client:
                    add:  5 - 6
                    ------------------------------------
                    Operation: add
                    Data 1:    5
                    Data 2:    6
                    ------------------------------------
                    Called function: add - with index: 0
                    Add Message: Test1
                    Internal add from operations
                    r1 = 11.000000
                    Spare info (func[]): 22
                    ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "op_handler.h"
#include "operations.h"

int socket_fd;


// The arithmetic operations ... one of these functions is selected at runtime
// These functions are called via function pointer (*func[function_idx].xfp)(par)
float Add(Parameters p) {
    printf ("Add Message: %s\n",p.comment);
    float rv = internal_add(p);
    return rv;
}

float Sub(Parameters p) {
    printf ("Sub Message: %s\n",p.comment);
    float rv = internal_sub(p);
    return rv;
}

float Mul(Parameters p) {
    printf ("Mul Message: %s\n",p.comment);
    float rv = internal_mul(p);
    return rv;
}

float Div(Parameters p) {
    printf ("Div Message: %s\n",p.comment);
    float rv = internal_div(p);
    return rv;
}


// create a socket for UDP and return the socket descriptor
int create_socket() {

   struct sockaddr_in servaddr;

   int sockfd = socket(AF_INET,SOCK_DGRAM,0);

   memset(&servaddr,sizeof(servaddr),0);
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   servaddr.sin_port=htons(LOCAL_SERVER_PORT);
   bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
   return sockfd;

}


// handle message from client
DataMessage rec_message(int fd) {

   struct sockaddr_in cliaddr;
   DataMessage new_msg;
   socklen_t len;
   int n;

      len = sizeof(cliaddr);
      printf("\nWaiting for message to be received from client ...\n");

      // receive message from client
      n = recvfrom(fd,&new_msg,sizeof(new_msg),0,(struct sockaddr *)&cliaddr,&len);
      if (n < 0) {
          printf("Cannot receive data");
          exit(0);
      }

      
      // send message to client
      sendto(fd,&new_msg,sizeof(new_msg),0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));

      printf("------------------------------------\n");
      printf("Received the following from client:\n");
      printf("%s:  ",new_msg.operation);
      printf("%d - ",new_msg.a);
      printf("%d\n",new_msg.b);
      printf("------------------------------------\n");
      return new_msg;
}


/* *** MAIN *** */
int main(int argc, char* argv[]) {

    Parameters  par;      // in parameters to the operation
    DataMessage rec_msg;  // received message from client

    // create socket and get message from client
    socket_fd = create_socket();
    rec_msg   = rec_message(socket_fd);
    
    // print out received message
    printf("Operation: %s\n",rec_msg.operation);
    printf("Data 1:    %d\n",rec_msg.a);
    printf("Data 2:    %d\n",rec_msg.b);
    printf("------------------------------------\n");

    // initialize container with all functions
    Container func[] = {
                         {Add,"add",22},
                         {Sub,"sub",33},
                         {Mul,"mul",44},
                         {Div,"div",55}
                       };


    // get size of func[]
    int zise = sizeof(func)/sizeof(func[0]);

    int r    = 0;         // return value from string compare, = 0 if hit
    int flag = 0;         // flag indicating valid function selected
    int function_idx = 0; // index for the decoded function

    // compare received string (1st field in DataMessage) with string in Container (2nd field)
    for (int i=0; i<zise; i++) {
        r = strncmp(rec_msg.operation,func[i].xfpstr,3);

        // if entered string equals string in Container then print out
        if (r == 0) {
            printf("Called function: %s - with index: %d\n",func[i].xfpstr,i);
            function_idx = i;
            flag = 1;
        }
    }

    // check if valid function name was sent
    if (flag == 0) {
        printf("Error, invalid function call!\n");
        exit(0);
    }

    // call selected function with its parameters via function pointer
    par.indata1 = rec_msg.a;
    par.indata2 = rec_msg.b;
    strcpy(par.comment,"Test1");
    printf("r1 = %f\n",(*func[function_idx].xfp)(par));
    printf("Spare info (func[]): %d\n",func[function_idx].z);
    printf("------------------------------------\n");

    return 0;
}

