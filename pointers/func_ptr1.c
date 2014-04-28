/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-07
    File        : func_ptr1.c
    Reference   : -
    Description : Test of pointer to a function.
*/

#include <stdio.h>

struct employee {
    char   name[31];
    char   address[80];
    int    age;
    float  salery;
};


typedef struct employee emp;


int compare_ages(const void *v1, const void *v2) {
    const emp *e1 = v1;
    const emp *e2 = v2;

    return e1->age - e2->age;
}


int main() {

    emp emps[] = {
        ("Bob",  "123 Hope St",   45, 45000.00),
        ("Tony", "124 Hope St",   99, 46000.00),
        ("Mary", "12 Banana Ave", 12, 20000.00),
        ("Sue",  "1000 Road Ave", 45, 90000.00),
        ("Fred", "32 Nowhere",    51, 49000.00)
    };


    qsort(emps,5,sizeof emps[0],compare_ages);

//    for (int i=0; i<5; i++) {
//    }

    return 0;
}
