CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall
#CFLAGS = -std=c99

m1: file_handler1.c
	$(CC) $(CFLAGS) file_handler1.c -o file_handler1

m2: file_handler2.c
	$(CC) $(CFLAGS) file_handler2.c -o file_handler2

m3: file_handler3.c
	$(CC) $(CFLAGS) file_handler3.c -o file_handler3

clean:
	rm -f a.out program.txt file_handler1 file_handler2 file_handler3 data_file2.txt data_file3.txt
