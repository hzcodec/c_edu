/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-17
    File        : ascii2int.c
    Reference   : -
    Description : Convert an ascii string to integer.
                  ASCII characters - '0' = 48
                                     '9' = 57
                                     '+' = 43
                                     '-' = 45
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _asc2int(const char* s) {

    int i = 0;

    while (*s != 0) {

        // '+' and '-' is outside
        if (*s >= '0' && *s <= '9') {

            // '5' - '0' = 53 - 48 = 5
            i = i * 10 + (*s - '0');
            s++;
        }

        else {
           return 0;
        }
    }    
    return i;
}


int asc2int(const char* s) {

    int sign = 1;

    if (*s == '+') {
        s++;
    }

    if (*s == '-') {
      sign = -1;
      s++;
    }

    return _asc2int(s) * sign;
}


/* *** MAIN *** */
int main(void) {

    char s[] = "5310";
    printf("'%s' => %d\n\n",s,asc2int(s));

    strcpy(s,"-346");
    printf("'%s' => %d\n\n",s,asc2int(s));
 
    return 0;
}

/*
  Result from run:
*/

