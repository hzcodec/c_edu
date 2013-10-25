CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

s1: server1.c
	$(CC) server1.c -o server1

c1: client1.c
	$(CC) client1.c -o client1

s2: server2.c
	$(CC) server2.c -o server2

c2: client2.c
	$(CC) client2.c -o client2

all: client1.c
	$(CC) client1.c -o client1 
	$(CC) server1.c -o server1 

clean:
	rm -f a.out server1 client1 server2 client2
