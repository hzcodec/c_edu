/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-28
    File        : pp_test1.c
    Reference   : 
    Description : Test of pointer to pointer.


      54   56   57   58   59   60   61   62   63   64   65   66   67   68
    +----+----+----+----+----+----+----+----+----+----+----+----+----+----+
    |    | 58 |    | 63 |    | 55 |    |    | h  | e  | l  | l  | o  | \0 |
    +----+----+----+----+----+----+----+----+----+----+----+----+----+----+
           ^          ^         ^
           |          |         |
    cp  ----          |         |
    c   ---------------         |
    cpp -------------------------

    c is the pointer to 'hello'
    cp is the pointer to c pointer
    cpp is the pointer to cp pointer

*/

#include <stdio.h>
#include <math.h>


/* *** MAIN *** */
int main(void) {

    const char *c     = "hello";
    const char **cp   = &c;        // assign address to c
    const char ***cpp = &cp;       // assign address to cp

    printf("Print out addresses to pointers\n");
    printf("*c: %s\n",c);
    printf("&c    address to c:     %08x\n",&c);
    printf("**c   address to c:     %08x\n",cp);
    printf("&cp   address to c*:    %08x\n",&cp);
    printf("***cp address to c*:    %08x\n",cpp);
    printf("&cp   address to c**:   %08x\n",&cpp);

    // increment pointer to pointer
    printf("Character: %c\n",**cp);
    c++;
    printf("Character: %c\n",**cp);
    c++;
    printf("Character: %c\n",**cp);
    c++;
    printf("Character: %c\n",**cp);
    c++;
    printf("Character: %c\n",**cp);
    
    return 0;
}

/*
  Result from run:
*/

