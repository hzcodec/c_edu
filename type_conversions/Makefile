CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

b1: byte2int_test1.c
	$(CC) $(CFLAGS) byte2int_test1.c -o byte2int_test1

b2: byte2int_test2.c
	$(CC) $(CFLAGS) byte2int_test2.c -o byte2int_test2

a1: ascii2char_test1.c
	$(CC) $(CFLAGS) ascii2char_test1.c -o ascii2char_test1

clean:
	rm -f a.out byte2int_test1 byte2int_test2 ascii2char_test1
