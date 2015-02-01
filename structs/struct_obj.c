/* 
    Auther      : Heinz Samuelsson
    Date        : 2015-02-01
    File        : struct_obj.c
    Reference   : stackoverflow.com/questions/12971995/how-pointers-to-function-as-struct-member-useful-in-c
    Description : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _man {
    char name[20];
    int  age;
    void (*speak)(char* text);
    void (*eat)(int* foodptr);
    void (*sleep)(int* hours);
};


void grijesh_speak(char* test) {
    printf("Speak: %s\n",test);
}

void grijesh_eat(int* food) {
    printf("Eat: %d\n",*food);
}

void grijesh_sleep(int* hours) {
    printf("Sleep: %d\n",*hours);
}


void init_struct(struct _man* man) {
    if (man == NULL) {
        man = malloc(sizeof(struct _man));
    }
    strcpy(man->name,"Grijesh");
    man->age = 25;
    man->speak = grijesh_speak;
    man->eat = grijesh_eat;
    man->sleep = grijesh_sleep;
}


/* *** MAIN *** */
int main(void) {

    int a=10;

    struct _man grijesh;
    init_struct(&grijesh);
    grijesh.speak("Babble dabble");
    grijesh.sleep(&a);

    return 0;

}
