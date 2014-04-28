/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-28
    File        : function_ptr2.c
    Reference   : 
    Description : Function pointers are pointers, i.e. variables, whtich point to
                  the address of a function. Since function pointer is nothing
		  else than a variable, it must be defined as usual.
		  Here an array of pointer is set up.
*/

#include <stdio.h>

// arithmetic operations
// one of these are selected at runtime
float Add (float a, float b) {return a+b;}
float Sub (float a, float b) {return a-b;}
float Mul (float a, float b) {return a*b;}
float Div (float a, float b) {return a/b;}


/* *** MAIN *** */
int main(void) {

    // array of function pointers
    float (*afp[4])(float,float);

    // assign all functions to the array
    afp[0] = Add;
    afp[1] = Sub;
    afp[2] = Mul;
    afp[3] = Div;

    // declare and assign function pointer
    float (*pt2Function)(float, float) = NULL;
    pt2Function = &Mul;

    // call function via pointer
    float r = (*pt2Function)(8,4);
    printf("r: = %f\n",r);

    pt2Function = &Add;
    r = (*pt2Function)(8,4);
    printf("r: = %f\n",r);


    // use array
    r = (*afp[0])(12,8);
    printf("r: = %f\n",r);

    r = (*afp[1])(12,8);
    printf("r: = %f\n",r);

    return 0;
}

/*
  Result from run:
*/

