# Nombre del ejecutable final
TARGET = programa

# Compilador C++ y opciones de compilación
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -g

# Archivos fuente e implementación
SRCS = particion.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(TARGET)

# Enlace de objetos
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencias de cabeceras
main.o: kruskal.hpp particion.hpp grafo.hpp grafo-ponderado.hpp
particion.o: particion.hpp

# Limpieza del proyecto
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean