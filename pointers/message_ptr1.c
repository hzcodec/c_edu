/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-08-20
    File        : message_ptr1.c
    Reference   : 
    Description : Function pointers.
*/

#include <stdio.h>
#include <string.h>

// define the parameter for the functions
typedef struct {
    float a;
    float b;
    char  message[100];
}Parameters;


// containers for the functions
typedef struct {
    float (*xfp)(Parameters p);
    int z;
}Container;

// the two arithmetic operations ... one of these functions is selected at runtime
float Add(Parameters p) {
    printf("Add message %s\n",p.message);
    return p.a+p.b;
}

float Sub(Parameters p) {
    printf("Sub message %s\n",p.message);
    return p.a-p.b;
}

float Mul(Parameters p) {
    printf("Sub message %s\n",p.message);
    return p.a*p.b;
}

float Div(Parameters p) {
    printf("Sub message %s\n",p.message);
    return p.a/p.b;
}

int main() {
  
    Parameters par;

    // initialize the container with all the functions
    Container func[] = {
                        {Add,22},
                        {Sub,33},
                        {Mul,44},
                        {Div,55}
                       };

    par.a = 99;
    par.b = 1;
    strcpy(par.message,"Test1");
    printf("r: %f\n",(*func[0].xfp)(par));
    printf("z: %d\n\n",func[0].z);

    par.a = 9;
    par.b = 2;
    strcpy(par.message,"Test2");
    printf("r: %f\n",(*func[1].xfp)(par));
    printf("z: %d\n\n",func[1].z);
    
    return 0;
}

/* Result:
     Add message Test1
     r: 100.000000
     z: 22
     
     Sub message Test2
     r: 7.000000
     z: 33
*/
