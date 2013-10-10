#include<stdio.h>

typedef struct {

    // coordinates
    int x1,y1;
    int x2,y2;
    int x3,y3;

    // scale factor
    float scale;

} triangle_t;


// prototypes
void PrintTriangle(triangle_t *t);
void ScaleTriangle(triangle_t *t);

// define a triangle
triangle_t blue_triangle = {
    .x1    = 99,
    .y1    = 77,
    .scale = 5
};

