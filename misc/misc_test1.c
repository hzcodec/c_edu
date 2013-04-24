/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-24
    File        : misc_test1.c
    Reference   : -
    Description : Test of switch function. Enter an operation (+/-) and a number.
                  A result is calculated based on the entered operation.
                  Example: Enter '+' '6' => 6
                           Enter '-' '2' => 4
*/

#include<stdio.h>


/* *** MAIN *** */
int main(void) {

    char line[100];
    int  result;
    char operator;
    int  value;

    result = 0;
  
    while(1) {

        printf("Result: %d\n",result);
        printf("Enter operation and number (q for quit): ");
    
        fgets(line,sizeof(line),stdin);
        sscanf(line,"%c %d",&operator,&value);
    
         if ((operator == 'q' || operator == 'Q'))
             break;
    
         switch(operator) {
             case '+':
                result += value; // add value to result
                break;
             case '-':
                 result -= value; // subtract value to result
                 break;
             default:
                 printf("Unknown operator '%c'\n",operator);
                 break;
         }
      }


    return 0;
}

