/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-05
    File        : function_ptr2.c
    Reference   : 
    Description : Test of function pointers and struct.
*/

#include <stdio.h>

typedef struct{
    float a;
    float b;
} Params;


// functions are selected at runtime
float Add (Params par) {return par.a+par.b;}
float Sub (Params par) {return par.a-par.b;}
float Mul (Params par) {return par.a*par.b;}
float Div (Params par) {return par.a/par.b;}


float Switch_With_Function_Ptr(Params par, float(*pt2Func)(Params)) {

    // call using a function pointer
    float result = pt2Func(par);
    return result;
}



/* *** MAIN *** */
int main(void) {

    Params par;
    float  rv;

    par.a = 3.0;
    par.b = 4.0;

    // call with function pointer
    rv = Switch_With_Function_Ptr(par,&Add);
    printf("rv: %f\n",rv);
    rv = Switch_With_Function_Ptr(par,&Sub);
    printf("rv: %f\n",rv);


    return 0;
}


/*
  Result from run:
*/

