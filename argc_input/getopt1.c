/*
   Auther:       Heinz Samuelsson
   Date:         2014-03-26
   File:         getopt1.c
   Reference:    youtube.com/watch?v=SjyR74lbZOc
   Description:  Example of how to use getopt().
                 Convert Farenheit to Centigrades and vice versa.

 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


void print_usage() {
    printf("Usage: temp -c <tempt> | temp -f <temp> \n");
    exit(2);
}


void print_farenheit(float temp) {
    float f = ((temp * 9) / 5) + 32;
    printf("%.2f Centigrade is %.2f Farenheit\n",temp,f);
}


void print_centigrade(float temp) {
    float c = ((temp - 32) * 5 / 9);
    printf("%.2f Farenheit is %.2f Centigrade\n",temp,c);
}


int main(int argc, char **argv) {

    // make sure there are two arguments
    if (argc < 2) {
        printf("To few arguments.\n");
        print_usage();
    }

    int option;
    int cflag = 0; // locking flags
    int fflag = 0;

    // c needs an argument, f needs an argument
    while ((option = getopt(argc, argv, "c:f:")) != -1)

            switch (option) {
            case 'c':
                    if (cflag) {
                        print_usage();
                    }
                    else {
                        cflag++;
                        fflag++;
                    }
                    print_farenheit(atof(optarg));
                    break;

            case 'f':
                    if (fflag) {
                        print_usage();
                    }
                    else {
                        fflag++;
                        cflag++;
                    }
                    print_centigrade(atof(optarg));
                    break;
            default:
                    printf("Error\n");
           }

    return 0;
}
