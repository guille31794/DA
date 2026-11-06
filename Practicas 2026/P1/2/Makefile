# Nombre del ejecutable final
TARGET = programa

# Compilador y opciones de compilación
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Lista de archivos fuente y sus correspondientes objetos
SRCS = particion.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Regla principal: construye el ejecutable
all: $(TARGET)

# Enlaza los archivos objeto (.o) para crear el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compila cada archivo .cpp a su archivo objeto .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Recompila main.o y particion.o si particion.hpp cambia
main.o: particion.hpp
particion.o: particion.hpp

# Limpia el proyecto borrando objetos y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)

# Evita conflictos con archivos que se llamen igual que estas reglas
.PHONY: all clean