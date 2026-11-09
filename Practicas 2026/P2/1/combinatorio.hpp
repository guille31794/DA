#ifndef COMBINATORIO_HPP_
#define COMBINATORIO_HPP_

#include <vector>
#include <algorithm>

using natural = unsigned long;

// ============================================================================
// 1. Algoritmo Recursivo Clásico (con simetría)
// ============================================================================
natural combinatorioRecursivoAux(natural n, natural k)
{
    if (k == 0 || k == n)
        return 1;
    return combinatorioRecursivoAux(n - 1, k - 1) + combinatorioRecursivoAux(n - 1, k);
}

natural combinatorioRecursivo(natural n, natural k)
{
    if (k > n)
        return 0;
    k = std::min(k, n - k); // Uso de la propiedad de simetría
    return combinatorioRecursivoAux(n, k);
}

// ============================================================================
// 1.1. Algoritmo Descendente Recursivo con Memorización (Top-Down)
// ============================================================================
natural combinatorioMemorizadoAux(natural n, natural k, std::vector<std::vector<natural>> &memo)
{
    if (k == 0 || k == n)
        return 1;
    if (memo[n][k] != 0)
        return memo[n][k]; // Subproblema ya resuelto

    memo[n][k] = combinatorioMemorizadoAux(n - 1, k - 1, memo) +
                 combinatorioMemorizadoAux(n - 1, k, memo);
    return memo[n][k];
}

natural combinatorioMemorizado(natural n, natural k)
{
    if (k > n)
        return 0;
    k = std::min(k, n - k); // Simetría
    std::vector<std::vector<natural>> memo(n + 1, std::vector<natural>(k + 1, 0));
    return combinatorioMemorizadoAux(n, k, memo);
}

// ============================================================================
// 1.2. Algoritmo Ascendente Iterativo (Bottom-Up)
// ============================================================================
natural combinatorioIterativo(natural n, natural k)
{
    if (k > n)
        return 0;
    k = std::min(k, n - k); // Simetría

    // Vector de tamaño k + 1 inicializado en 0 (Optimización espacial a 1D)
    std::vector<natural> C(k + 1, 0);
    C[0] = 1; // Caso base C(0, 0) = 1

    for (natural i = 1; i <= n; ++i)
    {
        // Recorrido inverso para no sobreescribir valores necesarios de la fila anterior
        for (natural j = std::min(i, k); j > 0; --j)
        {
            C[j] = C[j] + C[j - 1];
        }
    }

    return C[k];
}

#endif // COMBINATORIO_HPP_