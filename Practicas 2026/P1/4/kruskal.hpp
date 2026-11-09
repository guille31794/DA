#ifndef KRUSKAL_HPP_
#define KRUSKAL_HPP_

#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include "particion.hpp"
#include "grafo-ponderado.hpp"

// ============================================================================
// Sobrecarga de Operadores de Entrada/Salida para Grafos y Aristas Ponderadas
// ============================================================================

// Entrada de AristaPonderada
template <typename V, typename P>
std::istream &operator>>(std::istream &fe, AristaPonderada<V, P> &a)
{
    return fe >> a.primero() >> a.segundo() >> a.peso();
}

// Entrada de Grafo
template <typename V, typename A>
std::istream &operator>>(std::istream &fe, Grafo<V, A> &g)
{
    std::size_t n = 0;
    fe >> n;
    g = Grafo<V, A>(n);
    V u{}, v{};
    A a(u, v);
    while (fe >> a)
    {
        g.insertar(a);
    }
    return fe;
}

// Salida de AristaPonderada
template <typename V, typename P>
std::ostream &operator<<(std::ostream &fs, const AristaPonderada<V, P> &a)
{
    return fs << a.primero() << ' ' << a.segundo() << ' ' << a.peso();
}

// Salida de Grafo
template <typename V, typename A>
std::ostream &operator<<(std::ostream &fs, const Grafo<V, A> &g)
{
    fs << g.vertices() << '\n';
    auto &a = g.aristas();
    std::copy(std::begin(a), std::end(a), std::ostream_iterator<A>(fs, "\n"));
    return fs << std::flush;
}

// ============================================================================
// Algoritmo de Kruskal empleando Montículos (Min-Heap)
// ============================================================================

template <typename G>
G Kruskal(const G &g)
{
    using std::priority_queue;
    using std::size_t;
    using std::vector;
    using Arista = typename G::Arista;

    size_t n = g.vertices(); // Número de vértices
    G s(n);                  // Grafo solución
    Particion p(n);          // Estructura de partición con control de alturas

    // Comparador personalizado para formar un Min-Heap basado en el peso de las aristas
    auto comp = [](const Arista &a1, const Arista &a2)
    {
        return a1.peso() > a2.peso();
    };

    // 1. CONSTRUCCIÓN DEL MONTÍCULO: Construimos el Min-Heap a partir del contenedor de aristas
    // Tiempo de construcción (heapify): O(E), donde E es el número de aristas.
    const auto &listaAristas = g.aristas();
    priority_queue<Arista, vector<Arista>, decltype(comp)> monticulo(listaAristas.begin(), listaAristas.end(), comp);

    // 2. BÚSQUEDA Y SELECCIÓN DE ARISTAS
    size_t aristasAñadidas = 0;

    // Extraemos progresivamente la arista con menor peso restante del montículo
    while (aristasAñadidas < n - 1 && !monticulo.empty())
    {
        // Extraer el elemento mínimo del montículo en O(log E)
        Arista aristaActual = monticulo.top();
        monticulo.pop();

        // Obtenemos las raíces de las componentes conexas en la partición
        int origen = p.buscar(aristaActual.primero());
        int destino = p.buscar(aristaActual.segundo());

        // Si pertenecen a componentes distintas, no forma ciclo
        if (origen != destino)
        {
            p.unir(origen, destino);  // Unir ambas componentes[cite: 18, 19]
            s.insertar(aristaActual); // Insertar arista en la solución[cite: 14]
            aristasAñadidas++;
        }
    }

    return s;
}

#endif // KRUSKAL_HPP_