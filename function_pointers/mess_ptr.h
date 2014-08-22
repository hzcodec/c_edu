#ifndef MESS_PTR_H__
#define MESS_PTR_H__

// define the parameters for the functions
typedef struct {
    float a;
    float b;
    char  message[100];
}Parameters;


// container for the functions
typedef struct {
    float (*xfp)(Parameters p);
    char*  xfpstr;
    int   z;
}Container;

#endif
