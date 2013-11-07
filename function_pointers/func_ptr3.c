/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-05
    File        : function_ptr3.c
    Reference   : 
    Description : Test of function pointers and struct.
                  Run the program with 
		  > time ./func_ptr3.out
*/

#include <stdio.h>
#include <unistd.h>


typedef struct{
    float a;
    float b;
    char  c;
} Params;


// functions are selected at runtime
float Add (Params par) {

    if (par.c == 'C') {
        par.a = 7.0;
    }
    return par.a+par.b;
}


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

    par.c = 'C';
    rv = Switch_With_Function_Ptr(par,&Add);
    printf("rv: %f\n",rv);

    sleep(5);


    return 0;
}


/*
  Result from run:
*/

