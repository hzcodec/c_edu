CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

m1: mem_copy1.c
	$(CC) $(CFLAGS) mem_copy1.c -o mem_copy1

m2: mem_set1.c
	$(CC) $(CFLAGS) mem_set1.c -o mem_set1

clean:
	rm -f a.out mem_copy1 mem_set1
