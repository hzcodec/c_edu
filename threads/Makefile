CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -lpthread

t1: thread_test1.c
	$(CC) $(CFLAGS) thread_test1.c -o thread_test1

t2: thread_test2.c
	$(CC) $(CFLAGS) thread_test2.c -o thread_test2

t3: thread_test3.c
	$(CC) $(CFLAGS) thread_test3.c -o thread_test3

t4: thread_test4.c
	$(CC) $(CFLAGS) thread_test4.c -o thread_test4

clean:
	rm -f a.out thread_test1 thread_test2 thread_test3 thread_test4
