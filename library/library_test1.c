/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-22
    File        : library_test1.c
    Reference   : http://www.adp-gmbh.ch/cpp/gcc/create_lib.html
    Description : Test of static library.
                  To compile run (static library):
                      > make clean; make l1
                  or (shared library) 
                      > make clean; make l2
                  To run the file:
                      > ./mean_calculator<1/2>
*/

#include <stdio.h>
#include "calc_mean.h"

/* *** MAIN *** */
int main(void) {

    double m;

    m = mean(3.0,5.0);
    printf("Mean result: %3.2f\n",m);
    return 0;
}

/*
  Result from run:
    mean calculated
    Mean result: 4.00
*/

