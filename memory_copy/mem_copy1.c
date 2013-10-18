/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-18
    File        : mem_copy1.c
    Reference   : 
    Description : Test of memory copy function.
*/

#include <stdio.h>
#include <string.h>

/* *** MAIN *** */
int main(void) {

    char src[30] = "copy this string to dst1";
    char dst[30];
    char *p;

    printf("dst = \"%s\"\n",dst);
    p = memcpy(dst,src,sizeof(dst));
    printf("dst via pointer = \"%s\"\n",p);
    printf("dst via array   = \"%s\"\n",dst);
    
    return 0;
}

/*
  Result from run:
*/

