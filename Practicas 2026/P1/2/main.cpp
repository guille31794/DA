#include <iostream>
#include <iomanip>
#include "particion.hpp"

// Función auxiliar para imprimir la clase/representante de cada elemento
void mostrarParticion(const Particion& p, int n) {
    std::cout << "Elemento:    ";
    for (int i = 0; i < n; ++i) {
        std::cout << std::setw(3) << i << " ";
    }
    std::cout << "\nRepresentante:";
    for (int i = 0; i < n; ++i) {
        std::cout << std::setw(3) << p.buscar(i) << " "; // Busca el padre/raíz de 'i'
    }
    std::cout << "\n" << std::string(4 * n + 14, '-') << "\n";
}

int main() {
    const int N = 8;
    std::cout << "=== DEMOSTRACIÓN DE LA CLASE PARTICIÓ N ===\n\n";

    // 1. Creación de la partición inicial
    // Cada elemento [0..N-1] está en su propio conjunto autónomo.
    Particion p(N); //[cite: 1]
    std::cout << "1. Estado Inicial (Cada elemento es su propio representante):\n";
    mostrarParticion(p, N);

    // 2. Primeras uniones entre elementos individuales (Misma altura = 1)
    std::cout << "2. Uniendo (0, 1) y (2, 3)...\n";
    // Precondición de unir: Pasar raíces distintas.
    p.unir(p.buscar(0), p.buscar(1)); // Une conjunto {0} y {1}
    p.unir(p.buscar(2), p.buscar(3)); // Une conjunto {2} y {3}[cite: 3]
    mostrarParticion(p, N);

    // 3. Unión de árboles con diferentes alturas
    // El árbol {0, 1} ahora tiene altura 2 (raíz 0 con valor -2)[cite: 3].
    // El elemento 4 tiene altura 1 (raíz 4 con valor -1)[cite: 3].
    std::cout << "3. Uniendo el conjunto {0, 1} (representante 0) con el {4}...\n";
    std::cout << "   (El de mayor altura absorberá al de menor altura sin incrementar su altura total)\n";
    p.unir(p.buscar(0), p.buscar(4)); //[cite: 3]
    mostrarParticion(p, N);

    // 4. Unión de árboles con la misma altura para ver cómo sube la altura
    // El árbol {2, 3} tiene altura 2 (representante 2)[cite: 3].
    // El árbol {0, 1, 4} tiene altura 2 (representante 0)[cite: 3].
    std::cout << "4. Uniendo conjuntos de igual altura {0, 1, 4} y {2, 3}...\n";
    std::cout << "   (Al tener la misma altura, se unen y la altura del representante incrementa)\n";
    p.unir(p.buscar(0), p.buscar(2)); //[cite: 3]
    mostrarParticion(p, N);

    // 5. Comprobación de pertenencia al mismo conjunto
    std::cout << "5. Consultas con buscar():\n";
    int elemA = 3, elemB = 4;
    if (p.buscar(elemA) == p.buscar(elemB)) { //[cite: 3]
        std::cout << "   - Los elementos " << elemA << " y " << elemB 
                  << " PERTENECEN al mismo conjunto (Raíz común: " << p.buscar(elemA) << ").\n"; //[cite: 3]
    } else {
        std::cout << "   - Los elementos " << elemA << " y " << elemB 
                  << " NO pertenecen al mismo conjunto.\n";
    }

    int elemC = 3, elemD = 7;
    if (p.buscar(elemC) == p.buscar(elemD)) { //[cite: 3]
        std::cout << "   - Los elementos " << elemC << " y " << elemD 
                  << " PERTENECEN al mismo conjunto.\n";
    } else {
        std::cout << "   - Los elementos " << elemC << " y " << elemD 
                  << " NO pertenecen al mismo conjunto (Raíces: " 
                  << p.buscar(elemC) << " y " << p.buscar(elemD) << ").\n"; //[cite: 3]
    }

    return 0;
}