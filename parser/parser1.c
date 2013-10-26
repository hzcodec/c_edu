/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-26
    File        : parser1.c
    Reference   : mbed.org/forum/helloworld/topic/3496
    Description : String parsing.
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
 
 
char testStringBuffer[] = "$GPRMC,121212,A,4807.038,N,01131.000,E,022.4,084.4,030611,003.1,W*6A";
 
//number of comma seperated values in the data...TODO does this remain constant?
#define NUM_FIELDS  (12)
char* pFields[NUM_FIELDS];
 
 
// seperates the single input string in to numFields substrings
void ParseFields(char* inputBuffer, char** pFields, uint32_t numFields, char* delimiterChars) {

    char* pString = inputBuffer;
    char* pField;
    
    for(uint32_t i=0; i<numFields; i++) {
        pField = strtok(pString, delimiterChars);
 
        if(pField != NULL) {
            pFields[i] = pField;
        }
        else {
            pFields[i] = "";
        }
 
        /* to make strtok continue parsing the next field rather 
           than start again on the original string */
        pString = NULL;
    }
}
 
 
int main(int argc, char* argv[]) {

    ParseFields(testStringBuffer, pFields, NUM_FIELDS, ",");

    for(int i=0; i<NUM_FIELDS; i++) {
        printf("Result: %d - %s\n",i,pFields[i]);
    }

    return 0;
}
