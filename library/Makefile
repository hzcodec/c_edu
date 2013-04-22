CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

# creating a static library, run file mean_calculator1
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

clean:
	rm -f a.out mean_calculator1 mean_calculator2 calc_mean.o libmean.a libmean.so.1.0.1
