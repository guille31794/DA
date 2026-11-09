#ifndef KRUSKAL_HPP_
#define KRUSKAL_HPP_

#include <iostream>
#include <list>
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
// Algoritmo de Kruskal con Preordenación
// ============================================================================

template <typename G>
G Kruskal(const G &g)
{
    using std::list;
    using std::size_t;
    using Arista = typename G::Arista;

    size_t n = g.vertices();     // Número de vértices del grafo original
    G s(n);                      // Grafo solución (inicia con 'n' vértices y sin aristas)
    Particion p(n);              // Estructura de partición con 'n' conjuntos disjuntos
    list<Arista> c(g.aristas()); // Lista de aristas candidatas

    // 1. PREORDENACIÓN: Ordenamos las aristas candidatas de menor a mayor peso.
    c.sort([](const Arista &a1, const Arista &a2)
           { return a1.peso() < a2.peso(); });

    // 2. BÚSQUEDA Y SELECCIÓN DE ARISTAS
    size_t aristasAñadidas = 0;
    auto it = c.begin();

    // Procesamos aristas mientras no tengamos (n - 1) aristas en el árbol
    // y sigan existiendo candidatos por examinar.
    while (aristasAñadidas < n - 1 && it != c.end())
    {
        const Arista &aristaActual = *it;

        // Obtenemos los representantes/raíces de las componentes conexas de los extremos
        int origen = p.buscar(aristaActual.primero());
        int destino = p.buscar(aristaActual.segundo());

        // Si pertenecen a componentes conexas distintas, la arista no forma ciclo
        if (origen != destino)
        {
            p.unir(origen, destino);  // Fusionamos ambas componentes en la partición
            s.insertar(aristaActual); // Insertamos la arista en el grafo solución
            aristasAñadidas++;
        }

        ++it; // Pasar a la siguiente arista candidata
    }

    return s;
}

#endif // KRUSKAL_HPP_