.PHONY: clean
OBJS = main.o fib.o
CFLAGS = -Wall -g
LDFLAGS = -static
CC = musl-gcc
INCLUDES =
LIBS =

fib: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} ${LDFLAGS} -o $@ ${OBJS} ${LIBS}

fib.o: fib.c fib.h
	${CC} ${CFLAGS} ${LDFLAGS} ${INCLUDES} -c $< -o $@

main.o: main.c fib.h
	${CC} ${CFLAGS} ${LDFLAGS} ${INCLUDES} -c $< -o $@

clean:
	-rm -f *.o core *.core fib

