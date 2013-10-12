/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-10
    File        : triangle.c
    Reference   : -
    Description : -
*/

#include"triangle.h"

void PrintTriangle(triangle_t *t) {
    printf("x1: %d\n",t->x1);
    printf("y1: %d\n",t->y1);
}


void ScaleTriangle(triangle_t *t) {
    t->x1 = t->x1*t->scale;
    t->y1 = t->y1*t->scale;

    printf("Triangle is scaled up\n");
    printf("x1: %d\n",t->x1);
    printf("y1: %d\n",t->y1);
}


/* *** MAIN *** */
int main(void) {

    triangle_t red_triangle;
    triangle_t green_triangle;

    // declare a pointer to triangle_t
    triangle_t *p_triangle;
    // assigned the pointer to the green_triangle
    p_triangle= &green_triangle;

    red_triangle.x1    = 10;
    red_triangle.y1    = 30;
    red_triangle.scale = 2;

    PrintTriangle(&red_triangle);
    PrintTriangle(&blue_triangle);

    ScaleTriangle(&red_triangle);
    ScaleTriangle(&blue_triangle);

    // use the pointer to the green_triangle
    p_triangle->x1 = 44;
    p_triangle->y1 = 22;
    PrintTriangle(p_triangle);

    return 0;
}

/* Result from run:
     x1: 10
     y1: 30
     x1: 99
     y1: 77
     Triangle is scaled up
     x1: 20
     y1: 60
     Triangle is scaled up
     x1: 495
     y1: 385
     x1: 44
     y1: 22
*/
