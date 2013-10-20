CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

s1: struct_test1.c
	$(CC) $(CFLAGS) struct_test1.c -o struct_test1

s2: struct_test2.c
	$(CC) $(CFLAGS) struct_test2.c -o struct_test2

i1: init_struct.c
	$(CC) $(CFLAGS) init_struct.c -o init_struct

i2: init_struct2.c
	$(CC) $(CFLAGS) init_struct2.c -o init_struct2

clean:
	rm -f a.out struct_test1 struct_test2 init_struct init_struct2
