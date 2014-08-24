#ifndef MESS_PTR_H__
#define MESS_PTR_H__

#define LOCAL_SERVER_PORT 35000

// define the parameters for the operation functions
typedef struct {
    float indata1;
    float indata2;
    char  comment[100];
}Parameters;


// container for the functions
typedef struct {
    float (*xfp)(Parameters p);
    char*  xfpstr;
    int   z;
}Container;


// received message from client
typedef struct {
    char operation[8]; // corresponds to add, sub, mul, div
    int a;             // corresponds to indata1
    int b;             // corresponds to indata2
} DataMessage;

#endif
