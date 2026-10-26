CXX = g++
CXXFLAGS = -Wall -pedantic
LDFLAGS = 
LDLIBS = 

EXE = cajero
OBJS = fajo.o cajero.o main.o

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# Dependencias de cabeceras
fajo.o: fajo.hpp
cajero.o: cajero.hpp fajo.hpp
main.o: cajero.hpp

clean:
	rm -f $(OBJS) $(EXE) *.gch cajero