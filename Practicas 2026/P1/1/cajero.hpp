/*
    P1 - E1
*/

#include "fajo.hpp"

class cajero
{
public:
    cajero();
    fajos reintegrar(const fajos& caja, unsigned int cantidad);
    const fajos& obtenerCaja() const {return caja;} 
private:
    void creaCaja();

private:
    fajos caja;
};