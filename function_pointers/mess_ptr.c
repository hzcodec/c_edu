/*
    Auther      : Heinz Samuelsson
    Date        : 2014-08-21
    File        : mess_ptr2.c
    Reference   : -
    Description : Function pointers. (server)

                  Ex of how to run the program:
                    > ./messptr <function> <par1> <par2>
                    > ./messptr add 10 20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mess_ptr.h"
#include "operations.h"


// The two arithmetic operations ... one of these functions is selected at runtime
float Add (Parameters p) {
    printf ("Add Message: %s\n",p.message);
    float rv = internal_add(p);
    return rv;
}

float Sub (Parameters p) {
    printf ("Sub Message: %s\n",p.message);
    float rv = internal_sub(p);
    return rv;
}

float Mul (Parameters p) {
    printf ("Mul Message: %s\n",p.message);
    float rv = internal_mul(p);
    return rv;
}

float Div (Parameters p) {
    printf ("Div Message: %s\n",p.message);
    float rv = internal_div(p);
    return rv;
}


/* *** MAIN *** */
int main(int argc, char* argv[]) {

    Parameters par;

    // initialize container with all functions
    Container func[] = {
                         {Add,"add",22},
                         {Sub,"sub",33},
                         {Mul,"mul",44},
                         {Div,"div",55}
                       };


    // print out entered arguments
    printf("----------------------\n");
    printf("Number of arguments: %d\n",argc);
    printf("File name: %s\n",argv[0]);
    for (int i=1; i<argc; i++) {
        printf("Argument[%d]: %s\n",i,argv[i]);
    }
    printf("----------------------\n");


    // get size of func[]
    int z1 = sizeof(func);
    int z2 = sizeof(func[0]);
    int z3 = sizeof(func)/sizeof(func[0]);
    printf("Size of func[] : %d\n",z1);
    printf("Size of func[0]: %d\n",z2);
    printf("Length of func : %d\n",z3);
    printf("----------------------\n");


    int r    = 0;         // return value from string compare, = 0 if hit
    int flag = 0;         // flag indicating valid function selected
    int function_idx = 0; // index for the decoded function

    // compare entered string (1st argument) with string in Container (2nd field)
    for (int i=0; i<z3; i++) {
        r = strncmp(argv[1],func[i].xfpstr,3);

        // if entered string equals string in Container then print out
        if (r == 0) {
            printf("Called function: %s - with index: %d\n",func[i].xfpstr,i);
            function_idx = i;
            flag = 1;
        }
    }

    // check if valid function was entered at command line
    if (flag == 0) {
        printf("Error, invalid function call!\n");
        exit(0);
    }


    // call selected function with its parameters
    par.a = atoi(argv[2]);
    par.b = atoi(argv[3]);
    strcpy(par.message,"Test1");
    printf("r1 = %f\n",(*func[function_idx].xfp)(par));
    printf("----------------------\n");

    return 0;
}


/* Result:
     Number of arguments: 4
     File name: ./messptr
     Argument[1]: mul
     Argument[2]: 10
     Argument[3]: 89
     ----------------------
     Size of func[] : 48
     Size of func[0]: 12
     Length of func : 4
     ----------------------
     Called function: mul
     Function index: 2
     Mul Message: Test1
     r1 = 890.000000
     ----------------------
*/
