CXX = g++
CXXFLAGS = -Wall -pedantic
LDFLAGS = 
LDLIBS = 

EXE = cajero
OBJS = main.o fajo.o cajero.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

main.o: main.cpp cajero.hpp
	$(CXX) $(CXXFLAGS) -c $<

fajo.o: fajo.hpp
	$(CXX) $(CXXFLAGS) -c $<

cajero.o: cajero.cpp cajero.hpp
	$(CXX) $(CXXFLAGS) -c $<
clean: 
	rm -f $(OBJS) $(EXE)