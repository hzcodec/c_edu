CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

p1: pipe_write2.c
	$(CC) pipe_write2.c -o pipe_write2

p2: pipe_read2.c
	$(CC) pipe_read2.c -o pipe_read2

all: pipe_read.c
	$(CC) pipe_read.c -o pipe_read 
	$(CC) pipe_write.c -o pipe_write 

clean:
	rm -f a.out pipe_read pipe_write pipe_read2 pipe_write2
