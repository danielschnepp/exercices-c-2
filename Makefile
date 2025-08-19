CFLAGS=-Wall -Werror -pedantic -Og -g3 -std=c99
CFLAGS+=-Wno-deprecated-declarations
VPATH = exercices-2-c:transit
C=$(wildcard *.c )
ETAPE=$(C.c=)

all: $(ETAPE)


clean : 
	rm -f $(ETAPE)