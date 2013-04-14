/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : ptr_test6.c
    Reference   : en.wikipedia.org/wiki/Function_pointer
    Description : Test of pointer to a function.
*/

#include <stdio.h>
#include <math.h>

double f1(double z) {
    printf("Found f1\n");
    return 9.0;
}


// function taking a function pointer as an argument
double compute_sum(double (*funcp)(double), double lo, double hi) {

    double sum = 0.0;

    for (int i=0; i<=10; i++) {

        // use the function pointer 'funcp' to invoke the function
        double x = i/100.0 * (hi - lo) + lo;
        double y = (*funcp)(x);
        sum += y;
    }
    return sum;
}


/* *** MAIN *** */
int main(void) {

    double (*fp)(double); // function pointer
    double sum;
 
    // use 'sin()' as the pointed-to function
    fp  = &sin;
    sum = compute_sum(fp,0.0,1.0);
    printf("sum(sin): %f\n",sum);

    // use 'cos()' as the pointed-to function
    sum = compute_sum(&cos,0.0,1.0);
    printf("sum(cos): %f\n",sum);

    // use own declared function f1()
    sum = compute_sum(&f1,0.0,1.0);
    printf("sum(f1): %f\n",sum);
    
    return 0;
}

/*
  Result from run:
    sum(sin): 0.549496
    sum(cos): 10.980761
    Found f1
    Found f1
    Found f1
    Found f1
    Found f1
    Found f1
    Found f1
    Found f1
    Found f1
    Found f1
    Found f1
    sum(f1): 99.000000
*/

