/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-28
    File        : function_ptr3.c
    Reference   : 
    Description : Same as function_ptr2.c but using an struct as in parameter.
*/

#include <stdio.h>

typedef struct{
    float a;
    float b;
} Parameters;


// arithmetic operations
// one of these are selected at runtime
float Add (Parameters p) {return p.a+p.b;}
float Sub (Parameters p) {return p.a-p.b;}
float Mul (Parameters p) {return p.a*p.b;}
float Div (Parameters p) {return p.a/p.b;}


/* *** MAIN *** */
int main(void) {

    Parameters par;

    par.a = 99;
    par.b = 1;

    float (*afp[4])(Parameters);

    // assign all functions to the array
    afp[0] = Add;
    afp[1] = Sub;
    afp[2] = Mul;
    afp[3] = Div;

    float r = (*afp[0])(par);
    printf("r: = %f\n",r);

    return 0;
}

/*
  Result from run:
*/

