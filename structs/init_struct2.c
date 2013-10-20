/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-20
    File        : init_struct.c
    Reference   : stackoverflow.com/questions/749180/default-values-in-a-struct
    Description : Initialize a struct with a function.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int stuff_a;
    int stuff_b;
}stuff;


int stuffInit(int a, int b, stuff *this) {
    this->stuff_a = a;
    this->stuff_b = b;
    return 0;
}


/* *** MAIN *** */
int main(void) {

    stuff myStuff;

    stuffInit(1,2,&myStuff);

    printf("stuff_a: %d\n",myStuff.stuff_a);
    printf("stuff_b: %d\n",myStuff.stuff_b);

    stuff *dynamicStuff;
    dynamicStuff = malloc(sizeof(stuff));
    stuffInit(0,0,dynamicStuff);

    printf("stuff_a: %d\n",dynamicStuff->stuff_a);
    printf("stuff_b: %d\n",dynamicStuff->stuff_b);
    free(dynamicStuff);
    
    return 0;
}

/*
  Result from run:
    stuff_a: 1
    stuff_b: 2
    stuff_c: 0
    stuff_d: 0
*/

