/*
    P1 - E1
*/

#include <iostream>
#include "cajero.hpp"

int main(int argc, char** argv)
{
    cajero cajero;
    const fajos& caja = cajero.obtenerCaja();
    unsigned int cantidad = static_cast<unsigned int>(argc);

    if (cantidad < 1) {
        std::cout << "Nada que reintegrar" << std::endl;
    } if (!caja.empty()) {
        cajero.reintegrar(caja, cantidad);
    } else {
        std::cout << "Caja vacia, no se puede devolver nada" << std::endl;
    }

    return 0;
}