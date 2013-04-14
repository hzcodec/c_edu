/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-08
    File        : struct_test2.c
    Reference   : -
    Description : Test of struct and calling by reference.
*/

#include <stdio.h>
#include <string.h>  // strcpy function


// 'typedef' => no need to use 'struct <type> <myname>' for declaration
typedef struct {
    int  age;
    char name[20];
} PersonData;


int message(PersonData* self, int a, char* b) {
    self->age = a;
    strcpy(self->name,b);
    return 1;
}


/* *** MAIN *** */
int main(void) {

    PersonData  pd;
    // declare a pointer and assign address
    PersonData* data_p = &pd;

    int rv = message(data_p,10,"Kalle");    

    printf("rv  : %d\n",rv);
    printf("Age : %d\n",data_p->age);
    printf("Name: %s\n",data_p->name);

    // this is the same as above
    //printf("Name: %s\n",pd.name);

    return 0;
}

/*
  Result from run:
    rv  : 1
    Age : 10
    Name: Kalle
*/

