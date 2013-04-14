CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

p1: ptr_test1.c
	$(CC) $(CFLAGS) ptr_test1.c -o ptr_test1

p2: ptr_test2.c
	$(CC) $(CFLAGS) ptr_test2.c -o ptr_test2

p3: ptr_test3.c
	$(CC) ptr_test3.c -o ptr_test3

p4: ptr_test4.c
	$(CC) ptr_test4.c -o ptr_test4

p5: ptr_test5.c
	$(CC) ptr_test5.c -o ptr_test5

p6: ptr_test6.c
	$(CC) $(CFLAGS) -lm ptr_test6.c -o ptr_test6

clean:
	rm -f a.out ptr_test1 ptr_test2 ptr_test3 ptr_test4 ptr_test5 ptr_test6
