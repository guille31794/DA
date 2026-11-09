#include <iostream>
#include <chrono>
#include <iomanip>
#include "combinatorio.hpp"

int main()
{
    using namespace std::chrono;

    std::cout << std::setw(5) << "n"
              << std::setw(22) << "C(n, floor(n/2))"
              << std::setw(18) << "T. Rec (us)"
              << std::setw(18) << "T. Memo (us)"
              << std::setw(18) << "T. Iter (us)" << "\n";
    std::cout << std::string(81, '-') << "\n";

    for (natural n = 0; n <= 40; ++n)
    {
        natural k = n / 2;

        // 1. Algoritmo Recursivo Clásico
        auto t1 = high_resolution_clock::now();
        natural res = combinatorioRecursivo(n, k); // Guardamos el resultado en 'res'
        auto t2 = high_resolution_clock::now();
        double tiempoRec = duration<double, std::micro>(t2 - t1).count();

        // 2. Algoritmo con Memorización
        auto t3 = high_resolution_clock::now();
        combinatorioMemorizado(n, k); // Se ejecuta para medir tiempo sin guardar variable duplicada
        auto t4 = high_resolution_clock::now();
        double tiempoMemo = duration<double, std::micro>(t4 - t3).count();

        // 3. Algoritmo Iterativo
        auto t5 = high_resolution_clock::now();
        combinatorioIterativo(n, k); // Se ejecuta para medir tiempo sin guardar variable duplicada
        auto t6 = high_resolution_clock::now();
        double tiempoIter = duration<double, std::micro>(t6 - t5).count();

        // Imprimimos el resultado 'res' y los tiempos de cada método
        std::cout << std::setw(5) << n
                  << std::setw(22) << res
                  << std::setw(18) << std::fixed << std::setprecision(2) << tiempoRec
                  << std::setw(18) << tiempoMemo
                  << std::setw(18) << tiempoIter << "\n";
    }

    return 0;
}