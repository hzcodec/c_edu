CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -lpthread

t1: thread_test1.c
	$(CC) $(CFLAGS) thread_test1.c -o thread_test1

t2: thread_test2.c
	$(CC) $(CFLAGS) thread_test2.c -o thread_test2

clean:
	rm -f a.out thread_test1 thread_test2
