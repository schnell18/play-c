.PHONY: clean
OBJS = main.o
CFLAGS = -Wall -g
LDFLAGS =
CC = gcc
INCLUDES =
LIBS =

punct: main.c
	${CC} ${CFLAGS} ${LDFLAGS} ${INCLUDES} -o punct $<

clean:
	-rm -f *.o core *.core

