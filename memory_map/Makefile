CC     = gcc

CFLAGS = -std=c99
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wall

FILES  = regmap

r1: regmap.c
	$(CC) $(CFLAGS) regmap.c -o regmap

clean:
	rm -f a.out $(FILES)

