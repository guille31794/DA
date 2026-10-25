CC = gcc
CFLAGS = -pg
LDFLAGS = -pg

EXE = fibonacci
OBJS = main.o fibonacci-iterative.o fibonacci-recursive.o

all: ${EXE}

${EXE}: ${OBJS}
	${CC} ${LDFLAGS} -o $@ $^

${OBJS}: fibonacci.h

clean:
	${RM} ${RMFLAGS} ${EXE} ${OBJS} gmon.out

clean-all: clean
	${RM} ${RMFLAGS} *~ core
