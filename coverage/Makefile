CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -fprofile-arcs -ftest-coverage

c1: cover_test1.c
	$(CC) $(CFLAGS) cover_test1.c -o cover_test1

cov: cover_test1.c
	gcov -f cover_test1.c

clean:
	rm -f a.out cover_test1 *.gcno *.gcov *.gcda
