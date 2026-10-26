/*
    P1 - E1
*/

#include <fstream>
#include <algorithm>
#include "cajero.hpp"

cajero::cajero()
: caja()
{
    creaCaja();
}

void cajero::creaCaja()
{
    std::fstream file;
    unsigned cantidad, valor;
    
    file.open("caja.dat");
    
    while (file >> valor >> cantidad) {
        caja.push_back(fajo(valor, cantidad));
    }

    file.close();
}

fajos cajero::reintegrar(const fajos& caja, unsigned int cantidad) 
{
    fajos cambio;
    fajos c = caja;
    std::make_heap(c.begin(), c.end());

    while (cantidad > 0 && !caja.empty()) {
        fajo f = c.front();
        std::pop_heap(c.begin(), c.end());
        c.pop_back();
        unsigned n_monedas = std::min(f.unidades(), cantidad / f.valor());

        if (n_monedas > 0) {
            cambio.push_back(fajo(f.valor(), n_monedas));
            cantidad -= f.valor() * n_monedas;
        }
    }

    return cambio;
}