CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

s1: shm_server.c
	$(CC) shm_server.c -o shm_server

c1: shm_client.c
	$(CC) shm_client.c -o shm_client

a1: shared1.c
	$(CC) shared1.c -o shared1

a2: shared2.c
	$(CC) shared2.c -o shared2

clean:
	rm -f a.out shm_server shm_client shared1 shared2
