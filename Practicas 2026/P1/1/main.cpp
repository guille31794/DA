/*
    P1 - E1
*/

#include <cstdlib>
#include "cajero.hpp"

int main(int argc, char** argv)
{
    cajero cajero;
    const fajos& caja = cajero.obtenerCaja();

    if (argc < 2) {
        std::cout << "Uso: " << argv[0] << " <cantidad_a_reintegrar>" << std::endl;
        return 1;
    }

    unsigned int cantidad = static_cast<unsigned int>(std::atoi(argv[1]));

    if (cantidad < 1) {
        std::cout << "Nada que reintegrar" << std::endl;
    } else if (!caja.empty()) {
        std::cout << "Se devuelven: " << cajero.reintegrar(caja, cantidad) << std::endl;
    } else {
        std::cout << "Caja vacia, no se puede devolver nada" << std::endl;
    }

    return 0;
}