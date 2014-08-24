CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

p1: func_ptr1.c
	$(CC) $(CFLAGS) func_ptr1.c -o func_ptr1
	
p2: func_ptr2.c
	$(CC) $(CFLAGS) func_ptr2.c -o func_ptr2

p3: func_ptr3.c
	$(CC) $(CFLAGS) func_ptr3.c -o func_ptr3

p4: func_ptr3.c
	$(CC)  -c operations.c
	$(CC) operations.o $(CFLAGS) mess_ptr.c -o mess_ptr


p5: op_handler.c
	$(CC) -c operations.c
	$(CC) operations.o $(CFLAGS) op_handler.c -o op_handler
	$(CC) op_client.c -o op_client

clean:
	rm -f a.out func_ptr1 func_ptr2 func_ptr3 mess_ptr op_client op_handler
