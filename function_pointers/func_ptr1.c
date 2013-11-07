/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-05
    File        : function_ptr1.c
    Reference   : 
    Description : Test of function pointers.
*/

#include <stdio.h>

// functions are selected at runtime
float Add (float a, float b) {return a+b;}
float Sub (float a, float b) {return a+b;}
float Mul (float a, float b) {return a+b;}
float Div (float a, float b) {return a+b;}


// using a switch function to select operation
void Switch(float a, float b, char opCode) {
    float result;

    switch(opCode) {
        case '+' : result = Add(a,b); break;
        case '-' : result = Sub(a,b); break;
        case '*' : result = Mul(a,b); break;
        case '/' : result = Div(a,b); break;
    }

    printf("    Switch result: %f\n\n",result);
}

void Switch_With_Function_Ptr(float a, float b, float(*pt2Func)(float,float)) {

    if ((int)pt2Func > 0) {
        if (pt2Func == &Add) {
	    printf(" Add function has been called\n");
	}
        if (pt2Func == &Sub) {
	    printf(" Sub function has been called\n");
	}
        if (pt2Func == &Mul) {
	    printf(" Mul function has been called\n");
	}
        if (pt2Func == &Div) {
	    printf(" Div function has been called\n");
	}
    }

    // call using a function pointer
    float result = pt2Func(a,b);
    printf("    Result: %f\n",result);
}



/* *** MAIN *** */
int main(void) {

    // just call switch function
    Switch(2,5,'+');

    // call with function pointer
    Switch_With_Function_Ptr(8,5,&Add);

    // assign and declare a function pointer
    float (*pt2MyFunction)(float,float) = NULL;
    pt2MyFunction = &Div;
    float r = (*pt2MyFunction)(8,4);
    printf("    r: %f\n",r);

    return 0;
}


/*
  Result from run:

   Switch result: 7.000000

 Add function has been called
    Result: 13.000000
    r: 12.000000
*/

