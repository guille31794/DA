TARGET = programa
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: combinatorio.hpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean