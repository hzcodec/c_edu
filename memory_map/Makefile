CC     = gcc

CFLAGS = -std=c99
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wall

FILES  = regmap regmap32

r1: regmap.c
	$(CC) $(CFLAGS) regmap.c -o regmap

r2: regmap32.c
	$(CC) $(CFLAGS) regmap32.c -o regmap32

clean:
	rm -f a.out $(FILES)

