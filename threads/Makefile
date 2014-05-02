CC     = gcc
#CFLAGS = -std=c99 -pedantic -Werror -Wall -lpthread
CFLAGS = -std=c99 -Wall -lpthread
FILES1 = thread_test1 thread_test2 thread_test3 thread_test4
FILES2 = thread1 thread2 thread_test5

t1: thread_test1.c
	$(CC) $(CFLAGS) thread_test1.c -o thread_test1

t2: thread_test2.c
	$(CC) $(CFLAGS) thread_test2.c -o thread_test2

t3: thread_test3.c
	$(CC) $(CFLAGS) thread_test3.c -o thread_test3

t4: thread_test4.c
	$(CC) $(CFLAGS) thread_test4.c -o thread_test4

t5: thread_test5.c
	$(CC) $(CFLAGS) thread_test5.c -o thread_test5

s1: thread1.c
	$(CC) $(CFLAGS) thread1.c -o thread1

s2: thread2.c
	$(CC) $(CFLAGS) thread2.c -o thread2

all: thread1.c
	$(CC) $(CFLAGS) thread_test1.c -o thread_test1
	$(CC) $(CFLAGS) thread_test2.c -o thread_test2
	$(CC) $(CFLAGS) thread_test3.c -o thread_test3
	$(CC) $(CFLAGS) thread_test4.c -o thread_test4
	$(CC) $(CFLAGS) thread1.c -o thread1
	$(CC) $(CFLAGS) thread2.c -o thread2

clean:
	rm -f a.out $(FILES1) $(FILES2)
