/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-18
    File        : mem_set1.c
    Reference   : 
    Description : Test of memory set function.
*/

#include <stdio.h>
#include <string.h>

/* *** MAIN *** */
int main(void) {

    char dst[20];

    printf("dst before: %s\n",dst);
    memset(dst,56,sizeof(dst));
    printf("dst after: %s\n",dst);
    
    return 0;
}

/*
  Result from run:
    dst before: `�
    dst after: 88888888888888888888
*/

