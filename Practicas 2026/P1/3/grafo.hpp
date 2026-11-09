#ifndef GRAFO_HPP_
#define GRAFO_HPP_

#include <cstddef>		// std::size_t
#include <list>

// Arista.

template <typename V>
class Arista {
public:
  using Vertice = V;
  Arista(Vertice u, Vertice v): u{u}, v{v} {} 
  Vertice primero() const { return u; }
  Vertice segundo() const { return v; }
  Vertice& primero() { return u; }
  Vertice& segundo() { return v; }
private:
  Vertice u, v;
};

// Grafo.
//
// Grafo con un número n de vértices prefijado, representados de 0 a n - 1, al que solo es posible
// insertar aristas, es decir, pares de vértices. Es una estructura muy eficiente que puede
// emplearse con estructuras de partición para representar sus componentes conexas.

template <typename V, typename A = Arista<V>>
class Grafo {
public:
  using Vertice = V;
  using Arista = A;
  using Aristas = std::list<Arista>;
  Grafo(std::size_t n = 0): n{n} {}
  std::size_t vertices() const { return n; }
  const Aristas& aristas() const { return a; }
  void insertar(const Arista& b) { a.push_back(b); }
private:
  std::size_t n;
  Aristas a;
};

#endif
