/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-05-07
    File        : cover_test1.c
    Reference   : -
    Description : Test of coverage.
                  How to run:
                    > make clean; make c1; ./cover_test1; make cov

                  Result is in file cover_test1.c.gcov.
*/

#include <stdio.h>

void f1(int a) {
    printf("a: %d\n",a);
}

void f2(int b) {
    printf("b: %d\n",b);
}


/* *** MAIN *** */
int main(void) {

    f1(12);

//    f2(23);

    return 0;
}

/*
  Result from run:

    Function 'main'
    Lines executed:100.00% of 3
    
    Function 'f2'
    Lines executed:0.00% of 3
    
    Function 'f1'
    Lines executed:100.00% of 3
    
    File 'cover_test1.c'
    Lines executed:66.67% of 9
    cover_test1.c:creating 'cover_test1.c.gcov'
*/

