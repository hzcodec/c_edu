CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall


# creating a static library, run file mean_calculator1
# -L<path_to_lib>, -l<library_name>
# ar - archiver, to create a static file
l1: library_test1.c
	$(CC) -c calc_mean.c -o calc_mean.o
	ar rcs libmean.a calc_mean.o
	$(CC) -static library_test1.c -L. -lmean -o mean_calculator1


# creating a shared library, run file mean_calculator2
l2: library_test1.c
	$(CC) -c calc_mean.c -o calc_mean.o
	ar rcs libmean.a calc_mean.o
	$(CC) -c -fPIC calc_mean.c -o calc_mean.o
	$(CC) -shared -W1,-soname,libmean.so.1 -o libmean.so.1.0.1 calc_mean.o
	$(CC) library_test1.c -o mean_calculator2 -L. -lmean


# creating a shared library, run file libtest2
l3: library_test2.c
	$(CC) -c -Wall -Werror -fpic foo.c
	$(CC) -shared -o libfoo.so foo.o
	$(CC) -L. -Wl,-rpath=./ -Wall -o libtest2 library_test2.c -lfoo


# creating a static library, run file hello
# without using -L and -l switches
l4: library_test3.c
	$(CC) -Wall -c hello_fn.c
	$(CC) -Wall -c bye_fn.c
	ar cr libhello.a hello_fn.o bye_fn.o
	$(CC) library_test3.c libhello.a -o hello 


clean:
		rm -f a.out mean_calculator1 mean_calculator2 calc_mean.o libmean.a libmean.so.1.0.1 foo.o libfoo.so libtest2 libhello.a hello hello_fn.o bye_fn.o
