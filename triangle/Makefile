CC     = gcc
#CFLAGS = -std=c99 -pedantic -Werror -Wall
CFLAGS = -std=c99

m1: triangle.c
	$(CC) $(CFLAGS) triangle.c -o triangle

# gdb
mg: triangle.c
	$(CC) $(CFLAGS) -g triangle.c -o triangle

# assembly
ma: triangle.c
	$(CC) $(CFLAGS) -S triangle.c -o triangle

clean:
	rm -f a.out triangle
