#ifndef CALLBACK__
#define CALLBACK__

#include<stdio.h>

// pointer to a function with two parameters and returning void
typedef void (*MyCallback)(int a,int b);

// prototype declarations
void _set_callback(MyCallback callback);

#endif
