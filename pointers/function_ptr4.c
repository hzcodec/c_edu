/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-28
    File        : function_ptr4.c
    Reference   : -
    Description : -
*/

#include <stdio.h>
#include <string.h>

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

typedef struct{
    float a;
    float b;
    char  message[40];
} Parameters;


// arithmetic operations
// one of these are selected at runtime
float Add (Parameters p) {
    printf("Sent message: %s\n",p.message);
    return p.a+p.b;
}

float Sub (Parameters p) {
    printf("Sent message: %s\n",p.message);
    return p.a-p.b;
}

float Mul (Parameters p) {
    printf("Sent message: %s\n",p.message);
    return p.a*p.b;
}

float Div (Parameters p) {
    printf("Sent message: %s\n",p.message);
    return p.a/p.b;
}


/* *** MAIN *** */
int main(void) {

    Parameters par;

    par.a = 99;
    par.b = 1;
    strcpy(par.message,"Test1");

    float (*afp[4])(Parameters);

    // assign all functions to the array
    afp[0] = Add;
    afp[1] = Sub;
    afp[2] = Mul;
    afp[3] = Div;

    float r = (*afp[ADD])(par);
    printf("r: = %f\n",r);

    // new parameters
    par.a = 22;
    par.b = 77;
    strcpy(par.message,"Test2");

    r = (*afp[SUB])(par);
    printf("r: = %f\n",r);

    return 0;
}

/*
  Result from run:
*/

