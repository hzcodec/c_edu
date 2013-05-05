/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-05-05
    File        : ptr_test8.c
    Reference   : -
    Description : Return multiple values via struct.

                             t
                            ___
                           |   |
                     int a |   |
                           |___|
                           |   |
                    char b |   |
                           |___|
                
*/

#include <stdio.h>
#include <string.h>  // library is needed for strcpy

typedef struct {
    int a;
    char b[10];
} Tuple;


void f1(Tuple* r) {
    printf("Change the values in the struct\n");
    r->a = 200;
    strcpy(r->b,"Nisse");
    printf("r.x: %d\n",r->a);
    printf("r.y: %s\n\n",r->b);
}


Tuple f2() {
    Tuple my_tuple;
    my_tuple.a = 1;
    strcpy(my_tuple.b,"Olle");
    return my_tuple;
}


/* *** MAIN *** */
int main(void) {

    Tuple t = {99,"Kalle"};
    Tuple *t_ptr;
    Tuple t2;

    // assign address of struct to pointer
    t_ptr = &t;

    // print out with different methods
    printf("a: %d\n",t.a);
    printf("b: %s\n",t.b);

    f1(&t);

    // (*t_ptr).a is the same as t_ptr->a
    printf("*t_ptr a: %d\n",(*t_ptr).a);
    printf("*t_ptr b: %s\n",(*t_ptr).b);
    printf("t_ptr->a: %d\n",t_ptr->a);
    printf("t_ptr->b: %s\n",t_ptr->b);
    
    // set up via a function call
    t2 = f2();
    printf("t2.a: %d\n",t2.a);
    printf("t2.b: %s\n",t2.b);
    

    return 0;
}

/*
  Result from run:
*/

