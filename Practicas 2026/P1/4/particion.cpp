#include "particion.hpp"

// 1. Constructor: Crea 'n' conjuntos disjuntos iniciales.
// Cada elemento es su propia raíz con altura 1 (representado como -1).
Particion::Particion(int n)
: p(n, -1) {}

// 2. Buscar: Sigue los punteros del padre hasta encontrar la raíz.
// Como la función es 'const', se realiza una búsqueda directa sin compresión de caminos.
int Particion::buscar(int i) const
{
    while (p[i] >= 0) {
        i = p[i];
    }

    return i;
}

// 3. Unir: Une los árboles cuyas raíces son 'i' y 'j' mediante control de alturas.
// Precondición: i != j y ambos son raíces (p[i] < 0 y p[j] < 0).
void Particion::unir(int i, int j)
{
    // Como las alturas se guardan con signo negativo, menor valor numérico implica MAYOR altura.
    // Ej: -3 (altura 3) < -1 (altura 1)
    
    if (p[i] < p[j]) {
        // El árbol de 'i' es más alto que el de 'j'.
        // Hacemos que 'i' sea el padre de 'j' (la altura total no cambia).
        p[j] = i;
    } else if (p[i] > p[j]) {
        // El árbol de 'j' es más alto que el de 'i'.
        // Hacemos que 'j' sea el padre de 'i' (la altura total no cambia).
        p[i] = j;
    } else {
        // Ambos árboles tienen la misma altura.
        // Hacemos que 'i' sea el padre de 'j' e incrementamos en 1 la altura de 'i'.
        p[j] = i;
        p[i]--; // Al ser negativo, decrementar equivale a aumentar la altura (ej: -1 a -2).
    }
}


