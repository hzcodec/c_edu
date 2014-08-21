CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall
FILES1 = ptr_test1 ptr_test2 ptr_test3 ptr_test4 ptr_test5
FILES2 = ptr_test6 ptr_test7 ptr_test8 pp_test1 func_ptr1
FILES3 = function_ptr1 function_ptr2 function_ptr3 function_ptr4 message_ptr1

p1: ptr_test1.c
	$(CC) $(CFLAGS) ptr_test1.c -o ptr_test1

p2: ptr_test2.c
	$(CC) $(CFLAGS) ptr_test2.c -o ptr_test2

p3: ptr_test3.c
	$(CC) ptr_test3.c -o ptr_test3

p4: ptr_test4.c
	$(CC) ptr_test4.c -o ptr_test4

p5: ptr_test5.c
	$(CC) $(CFLAGS) ptr_test5.c -o ptr_test5

p6: ptr_test6.c
	$(CC) $(CFLAGS) -lm ptr_test6.c -o ptr_test6

p7: ptr_test7.c
	$(CC) $(CFLAGS) -lm ptr_test7.c -o ptr_test7

p8: ptr_test8.c
	$(CC) ptr_test8.c -o ptr_test8

p9: pp_test1.c
	$(CC) pp_test1.c -o pp_test1

f1: func_ptr1.c
	$(CC) $(CFLAGS) func_ptr1.c -o func_ptr1

q1: function_ptr1.c
	$(CC) $(CFLAGS) function_ptr1.c -o function_ptr1

q2: function_ptr2.c
	$(CC) $(CFLAGS) function_ptr2.c -o function_ptr2

q3: function_ptr3.c
	$(CC) $(CFLAGS) function_ptr3.c -o function_ptr3

q4: function_ptr4.c
	$(CC) $(CFLAGS) function_ptr4.c -o function_ptr4

f2: message_ptr1.c
	$(CC) $(CFLAGS) message_ptr1.c -o message_ptr1

clean:
	rm -f a.out $(FILES1) $(FILES2) $(FILES3)
