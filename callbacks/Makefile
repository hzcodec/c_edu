CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

c1: callback_test1.c
	$(CC) $(CFLAGS) callback_test1.c -o callback_test1


c2: callback_test2.c
	$(CC) $(CFLAGS) -I. -c callback_test2.c -o cb_test.o
	$(CC) $(CFLAGS) -I. -c callback.c -o cb.o
	$(CC) $(CFLAGS) -I. cb_test.o cb.o -o callback_test

clean:
	rm -f a.out callback_test1 callback_test cb.o cb_test.o
