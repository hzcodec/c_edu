CC     = gcc
#CFLAGS = -std=c99 -pedantic -Werror -Wall
CFLAGS = -std=c99
FILES  = a.out argc_test1 argc_test2 argc_test3 getopt1 getopt2

a1: argc_test1.c
	$(CC) $(CFLAGS) argc_test1.c -o argc_test1

a2: argc_test2.c
	$(CC) $(CFLAGS) argc_test2.c -o argc_test2

a3: argc_test3.c
	$(CC) $(CFLAGS) argc_test3.c -o argc_test3

g1: getopt1.c
	$(CC) $(CFLAGS) getopt1.c -o getopt1

g2: getopt2.c
	$(CC) $(CFLAGS) getopt2.c -o getopt2

clean:
	rm -rf $(FILES)
