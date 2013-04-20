CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall


h1: hex_test1.c
	$(CC) $(CFLAGS) hex_test1.c -o hex1

h2: hex_test2.c
	$(CC) $(CFLAGS) hex_test2.c -o hex2

h3: hex_test3.c
	$(CC) $(CFLAGS) hex_test3.c -o hex3

h4: hex_test4.c
	$(CC) -std=c99 hex_test4.c -o hex4


all:
	$(CC) $(CFLAGS) hex_test1.c -o hex1
	$(CC) $(CFLAGS) hex_test2.c -o hex2
	$(CC) $(CFLAGS) hex_test3.c -o hex3
	$(CC) -std=c99 hex_test4.c  -o hex4

clean:
	\rm -f *.o a.out hex1 hex2 hex3 hex4
