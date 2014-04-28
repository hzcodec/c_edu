/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-28
    File        : function_ptr1.c
    Reference   : 
    Description : Select a function either by a pointer or a switch
                  selection.

*/

#include <stdio.h>

// arithmetic operations
// one of these are selected at runtime
float Add (float a, float b) {return a+b;}
float Sub (float a, float b) {return a-b;}
float Mul (float a, float b) {return a*b;}
float Div (float a, float b) {return a/b;}


// switch statment - <opCode> specifies which operation to execute
void Switch(float a, float b, char opcode) {
    printf("Function: \"%s\",.\n",__func__);
    float result;

    switch (opcode) {
	case '+': result = Add(a,b); break;
	case '-': result = Sub(a,b); break;
	case '*': result = Mul(a,b); break;
	case '/': result = Div(a,b); break;
    }
    printf("  Switch: %f\n",result);
}


// use function pointer instead
void Switch_With_Function_Pointer(float a, float b, float (*pt2Func)(float, float)) {

    printf("This is line %d in file \"%s\".\n",__LINE__,__FILE__);
    printf("Function: \"%s\".\n",__func__);

//    if (pt2Func > 0) {
	if (pt2Func == &Add)
	    printf("  Add function has been called\n");
	else if (pt2Func == &Sub)
	    printf("  Sub function has been called\n");
	else if (pt2Func == &Mul)
	    printf("  Mul function has been called\n");
	else if (pt2Func == &Div)
	    printf("  Div function has been called\n");
	else
	    printf("\nError\n");
//    }

    // call using function pointer
    float result = pt2Func(a,b);
    printf("  Result: %f\n",result);
}


/* *** MAIN *** */
int main(void) {

    printf("Function: \"%s\".\n",__func__); 
    // just call switch function
    Switch(2,5,'+');

    // call with function as in parameter
    Switch_With_Function_Pointer(2,5,&Sub);
    Switch_With_Function_Pointer(2,5,&Mul);

    // declare and assign a function pointer
    float (*pt2Function)(float, float) = NULL;
    pt2Function = &Div;

    // call function via pointer
    float r = (*pt2Function)(8,4);
    printf("r = %f\n",r);

    pt2Function = &Mul;
    r = (*pt2Function)(8,4);
    printf("r = %f\n",r);

    return 0;
}

/*
  Result from run:
*/

