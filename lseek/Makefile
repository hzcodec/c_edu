CC     = gcc
CFLAGS = -std=c99 -Wall

clean:
	\rm -f *.o a.out lseek1 hexdump fille.txt

l1: lseek1.c
	$(CC) $(CFLAGS) lseek1.c -o lseek1

h1: hexdump.c
	$(CC) $(CFLAGS) hexdump.c -o hexdump

all:
	$(CC) $(CFLAGS) lseek1.c -o lseek1
	$(CC) $(CFLAGS) hexdump.c -o hexdump

