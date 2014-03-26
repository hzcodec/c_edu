/*
   Auther:       Heinz Samuelsson
   Date:         2014-03-26
   File:         getopt2.c
   Reference:    https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/getopt.html
   Description:  Example of how to use getopt().
                 How to run:
                 > ./getopt3 -f name1 88 -s name2 99 -d
                 > ./getopt3 -f name1 77
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

// define arguments
struct globalArgs_t {
    int   debug;
    char* FName;
    char* SName;
}globalArgs;


int main(int argc, char **argv) {

    extern char *optarg;  // used by getopt()
    extern int  optind;   // used by getopt()
    int c;
    int err             = 0;
    static char usage[] = "usage: %s [-ds] -f fname name [name ...]\n";
    globalArgs.FName    = "default name FName";
    globalArgs.SName    = "default name SName";
    int debug = 0;

    while ((c = getopt(argc, argv, "df:s:")) != -1)
            switch (c) {
            case 'd':
                    debug = 1;
                    globalArgs.debug = 1;
                    break;
            case 'f':
                    globalArgs.FName = optarg;
                    break;
            case 's':
                    globalArgs.SName = optarg;
                    break;
            case '?':
                    err = 1;
                    break;
            }

    if ((optind+1) > argc) {
            /* need at least one argument (change +1 to +2 for two, etc. as needeed) */
            printf("optind = %d, argc=%d\n", optind, argc);
            fprintf(stderr, "%s: missing name\n", argv[0]);
            fprintf(stderr, usage, argv[0]);
            exit(1);
    }

    else if (err) {
            fprintf(stderr, usage, argv[0]);
            exit(1);
    }

    /* see what we have */
    printf("debug = %d\n",globalArgs.debug);
    printf("fname = \"%s\"\n",globalArgs.FName);
    printf("sname = \"%s\"\n",globalArgs.SName);

    printf("Number of arguments: %d\n",argc);
    printf("optind:              %d\n",optind);

    /* these are the arguments after the command-line options */
    if (optind < argc)
            for (; optind < argc; optind++) {
                    printf("argument: \"%s\"\n", argv[optind]);
                    printf("optind: \"%d\"\n", optind);
            }
    else {
            printf("no arguments left to process\n");
    }

    return 0;
}
