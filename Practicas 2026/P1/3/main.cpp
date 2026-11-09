#include <iostream>
#include <fstream>
#include "grafo-ponderado.hpp"
#include "kruskal.hpp"

int main() {
    std::string nombreArchivo = "grafo.dat";
    std::ifstream fe(nombreArchivo);

    if (!fe.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo '" << nombreArchivo << "'.\n";
        return 1;
    }

    // Instanciamos un Grafo Ponderado con vértices de tipo int y pesos double
    GrafoPonderado<int, double> g;

    // Leemos el grafo desde el fichero usando el operador >> sobrecargado
    fe >> g;
    fe.close();

    std::cout << "=== GRAFO ORIGINAL LEÍDO DE '" << nombreArchivo << "' ===\n";
    std::cout << g << "\n";

    // Calculamos el Árbol de Expansión Mínimo (MST) mediante Kruskal
    GrafoPonderado<int, double> mst = Kruskal(g);

    std::cout << "=== ÁRBOL DE EXPANSIÓN MÍNIMO (KRUSKAL) ===\n";
    std::cout << mst;

    // Calculamos el peso total del árbol obtenido
    double pesoTotal = 0.0;
    for (const auto& arista : mst.aristas()) {
        pesoTotal += arista.peso();
    }
    std::cout << "Peso total del árbol: " << pesoTotal << "\n";

    return 0;
}