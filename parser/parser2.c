/* 
    Auther      : Heinz Samuelsson
    Date        : 2015-09-24
    File        : parser2.c
    Reference   : -
    Description : Parsing a port name string and map it to a port number.

     DIAG_PORT_DEF
     +------------------------+
     |  char portName         |
     |  int  portNumber       |<-----
     +------------------------+     |
                                    |
                                    |
     DIAG_PORT_LIST                 |
     +------------------------------------+
     |  DIAG_PORT_DEF* diagPortList       |
     |  int            DiagPortListLength |
     +------------------------------------+
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


typedef enum
{
  PORT_ILLEGAL = 0,
  PORT_LAN_1   = 11,
  PORT_LAN_2   = 22,
  PORT_LAN_3   = 33,
  PORT_LAN_4   = 44,
  PORT_LAN_5   = 55,
} MY_PORT;


typedef struct
{
  char portName[7];
  int  portNumber;
} DIAG_PORT_DEF;


// list of port names and its corresponding number
static DIAG_PORT_DEF DIAG_PORT_DEFINITIONS[] = {
                                                 {"lan1",   PORT_LAN_1},
                                                 {"lan2",   PORT_LAN_2},
                                                 {"lan3",   PORT_LAN_3},
                                                 {"lan4_t", PORT_LAN_4},
                                                 {"lan5",   PORT_LAN_5},
                                                };


// contains a struct and the length of an array
typedef struct
{
  DIAG_PORT_DEF* diagPortList;
  int            diagPortListLength;
} DIAG_PORT_LIST;


// populate struct DIAG_PORT_LIST with a list of port names and the structs length
DIAG_PORT_LIST DIAG_PORTS = {DIAG_PORT_DEFINITIONS, sizeof(DIAG_PORT_DEFINITIONS) / sizeof(DIAG_PORT_DEFINITIONS[0])};


int parsePortString(const char* arg)
{
  int          port = 0;
  unsigned int longestMatch = 0;

  for (size_t i = 0; i < DIAG_PORTS.diagPortListLength; i++)
  {
    if (strncmp(arg,
                DIAG_PORTS.diagPortList[i].portName,
                strlen(DIAG_PORTS.diagPortList[i].portName)) == 0)
    {
      if (strlen(DIAG_PORTS.diagPortList[i].portName) > longestMatch)
      {
        port = DIAG_PORTS.diagPortList[i].portNumber;
        longestMatch = strlen(DIAG_PORTS.diagPortList[i].portName);
      }
    }
  }
  return port;
}


int main(int argc, char *argv[])
{

  printf("Size of port definitions:    %d\n", sizeof(DIAG_PORT_DEFINITIONS));
  printf("Size of port definitions[0]: %d\n", sizeof(DIAG_PORT_DEFINITIONS[0]));
  printf("Size of struct:              %d\n\n", sizeof(DIAG_PORT_DEFINITIONS) / sizeof(DIAG_PORT_DEFINITIONS[0]));
  printf("Port list length [0]: %d\n", strlen(DIAG_PORTS.diagPortList[0].portName));
  printf("Port list length [3]: %d\n", strlen(DIAG_PORTS.diagPortList[3].portName));
  printf("Port name [0]: %s\n", DIAG_PORTS.diagPortList[0].portName);
  printf("Port name [3]: %s\n\n", DIAG_PORTS.diagPortList[3].portName);

  char portString[10] = "lan2";
  int port = parsePortString(portString);
  printf("Port (lan2): %d\n", port);

  strcpy(portString, "lan3");
  port = parsePortString(portString);
  printf("Port (lan3): %d\n", port);

  strcpy(portString, "lan5");
  port = parsePortString(portString);
  printf("Port (lan5): %d\n", port);

  return 0;
}


/* Result:
     Size of port definitions:    60
     Size of port definitions[0]: 12
     Size of struct:              5
     
     Port list length [0]: 4
     Port list length [3]: 6
     Port name [0]: lan1
     Port name [3]: lan4_t
     
     Port (lan2): 22
     Port (lan3): 33
     Port (lan5): 55
*/
