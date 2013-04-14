/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-08
    File        : struct_test1.c
    Reference   : -
    Description : Test of struct, malloc and pointer.
*/

#include <stdio.h>
#include <stdlib.h>  // malloc and free function
#include <string.h>  // strcpy function


// 'typedef' => no need to use 'struct <type> <myname>' for declaration
typedef struct {
    int  age;
    char name[20];
} PersonData;


/* *** MAIN *** */
int main(void) {

    // allocate space
    PersonData* data_p;
    data_p = (PersonData*)malloc(sizeof(PersonData));

    // declare an object of PersonData
    PersonData data1;


    // print address of data_p
    printf("Address of data_p    : %p\n",(void*)data_p);
    // print size of object
    printf("Size of PersonData is: %d\n\n",sizeof(PersonData));


    // check if memory is available
    if (data_p != NULL) {
        data1.age = 5;
        strcpy(data1.name,"Kalle");
        printf("Age for data1 : %d\n",data1.age);
        printf("Name for data1: %s\n",data1.name);
    }


    // check if memory is available
    if (data_p != NULL) {
        data_p->age = 18; // use '->' since referenced by a pointer
        strcpy(data_p->name,"Nisse");
        printf("Age for data1 : %d\n",data_p->age);
        printf("Name for data1: %s\n",data_p->name);
    }

    // free allocated memory
    free(data_p);

    return 0;
}

/*
  Result from run:
    Address of data_p    : 0x13f0008
    Size of PersonData is: 24
    
    Age for data1 : 5
    Name for data1: Kalle
    Age for data1 : 18
    Name for data1: Nisse
*/

