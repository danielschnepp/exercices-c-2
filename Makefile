CFLAGS=-Wall -Werror -pedantic -Og -g3 -std=c99
CFLAGS+=-Wno-deprecated-declarations
C=$(wildcard *.c )
ETAPE=$(C.c=)

all: $(ETAPE)

clean : 
	rm -f $(ETAPE)