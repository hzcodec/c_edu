CC       = gcc
CFLAGS   = -std=c99 -W -Wall
INCLUDES = -I ./include
SRCS     = src/file1.c src/plot.c
HDRS     = include/plot.h

t1: src/file1.c
	$(CC) $(CFLAGS) src/plot.c -o build/plot.o -c -I ./include
	$(CC) $(CFLAGS) src/file1.c -o build/file1.o -c -I ./include
	$(CC) $(CFLAGS) -o pgm1 build/file1.o build/plot.o

t2: src/plot.c
	$(CC) $(CFLAGS) src/plot.c -o build/plot.o -c -I ./include

t3: src/file1.c
	$(CC) $(CFLAGS) src/file1.c -o build/file1.o -c -I ./include

t4: src/file1.c
	$(CC) $(CFLAGS) -o pgm1 build/file1.o build/plot.o


# create a static library
all: t5 t6 

t5: src/plot.c
	$(CC) $(CFLAGS) -c -o build/staticplot.o src/plot.c
	ar rcs build/libstaticplot.a build/staticplot.o

t6: src/file1.c
	#$(CC) $(CFLAGS) src/file1.c -static build/libstaticplot.a -I ./include -o pgm2
	$(CC) $(CFLAGS) $(INCLUDES) src/file1.c -static build/libstaticplot.a -o pgm2


tar:
	#tar cfv jennie.tar src/file1.c src/plot.c include/plot.h
	tar cfv jennie.tar $(SRCS) $(HDRS)

# clean all directories
clean:
	rm -f build/*.o build/libstaticplot.a staticplot.o pgm1 pgm2 jennie.tar
