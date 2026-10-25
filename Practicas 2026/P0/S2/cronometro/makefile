CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
EXE = prueba
OBJS = prueba.o

${EXE}: ${OBJS}
	${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

${OBJS}: cronometro.hpp

clean:
	${RM} ${EXE} ${OBJS} *~
